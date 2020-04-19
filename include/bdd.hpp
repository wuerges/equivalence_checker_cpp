#pragma once

#include <vector>

using std::vector;
using std::pair;

struct Node {
    int pos, neg, var;
};

struct BDD {

    int var_begin, var_end, index;

    vector<Node> adjacency;
    vector<vector<int>> representatives;

    BDD(int max_size, int var_begin, int var_end)
    : var_begin(var_begin), var_end(var_end), index(var_end),
      adjacency(max_size) ,
      representatives(max_size)
    {
        for(int i = var_begin; i < var_end; ++i) {
            adjacency[i] = Node{1, 0, i};
            representatives[i].push_back(i);
        }
    }


    int _and_(int x, int y) {
        if(x==1) {
            return y;
        }
        if(y==1) {
            return x;
        }
        if(x==0 || y == 0) {
            return 0;
        }

        int z = index++;

        if (adjacency[x].var == adjacency[y].var) {
            adjacency[z].var = adjacency[x].var;
            adjacency[z].pos = _and_(adjacency[y].pos, adjacency[x].pos);
            adjacency[z].neg = _and_(adjacency[y].neg, adjacency[x].neg);
        }
        else if(adjacency[x].var < adjacency[y].var) {
            adjacency[z].var = adjacency[x].var;
            adjacency[z].pos = _and_(adjacency[x].pos, y);
            adjacency[z].neg = _and_(adjacency[x].neg, y);
        }
        else  {
            adjacency[z].var = adjacency[y].var;
            adjacency[z].pos = _and_(adjacency[y].pos, x);
            adjacency[z].neg = _and_(adjacency[y].neg, x);
        }

        return z;
    }
};