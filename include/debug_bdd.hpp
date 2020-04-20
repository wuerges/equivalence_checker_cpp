#pragma once

#include <bdd.hpp>

#include <iostream>
#include <set>
using std::cout;
using std::set;



void mark_visibles(const BDD & bdd, int x, set<int> &visible) {
    if(x == 0 || x == 1) {
        return;
    }
    visible.insert(x);
    mark_visibles(bdd, bdd.adjacency[x].pos, visible);
    mark_visibles(bdd, bdd.adjacency[x].neg, visible);
}

void print_bdd(const BDD & bdd, int x,bool root=true) {

    if(root) {
        set<int> visible;
        mark_visibles(bdd, x, visible);
        cout << "digraph G {\n";
        cout << "0 [shape=rect];\n";
        cout << "1 [shape=rect];\n";

        for(int i = 2; i < bdd.index; ++i) {
            if(visible.count(i) > 0) {
                cout << i<< " [style=bold,label=\"" << i << ":" << bdd.adjacency[i].var << "\"];\n";
            }
        }
    }

    if(x != 0 && x != 1) {
        cout << x << "->" << bdd.adjacency[x].pos << ";\n";
        cout << x << "->" << bdd.adjacency[x].neg << "[style=dashed];\n";

        print_bdd(bdd, bdd.adjacency[x].pos, false);
        print_bdd(bdd, bdd.adjacency[x].neg, false);
    }

    if(root) {
        cout << "}\n";
    }

}