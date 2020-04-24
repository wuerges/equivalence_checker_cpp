#pragma once

#include <vector>

using std::vector;
using std::pair;

struct Nand {

    using Edge = pair<bool, int>;

    int input_begin, input_end, output_begin, output_end;
    vector<vector<Edge>> adjacency;


    Nand(int input_begin, int input_end, int output_begin, int output_end)
    : input_begin(input_begin), input_end(input_end), output_begin(output_begin), output_end(output_end),
      adjacency(input_end - input_begin + output_end - output_begin)
    {

    }

    int new_vertex() {
        int out = adjacency.size();
        adjacency.push_back({});
        return out;
    }

    int _and_(const vector<int> & inputs) {
        int out = new_vertex();
        for(int i : inputs) {
            adjacency[i].emplace_back(true, out);
        }
        return out;
    }

    int _nand_(const vector<int> & inputs) {
        int out = new_vertex();
        int aux = _and_(inputs);
        adjacency[aux].emplace_back(false, out);
        return out;
    }

    int _nor_(const vector<int> & inputs) {
        int out = new_vertex();
        for(int i : inputs) {
            adjacency[i].emplace_back(false, out);
        }
        return out;
    }

    int _or_(const vector<int> & inputs) {
        int out = new_vertex();
        int aux = _nor_(inputs);
        adjacency[aux].emplace_back(false, out);
        return out;
    }

};