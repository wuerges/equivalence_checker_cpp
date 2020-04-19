#pragma once

#include <bdd.hpp>

#include <iostream>
using std::cout;

void print_ident(int ident, char c) {
    for(int i = 0; i < ident; ++i) {
        cout << c;
    }
}

void print_bdd(const BDD & bdd, int x,int ident) {
    if(x== 0) {
        print_ident(ident, ' ');
        cout << "[0]\n";
        return;
    }
    if(x==1) {
        print_ident(ident, ' ');
        cout << "[1]\n";
        return;
    }

    print_bdd(bdd, bdd.adjacency[x].neg, ident+1);

    print_ident(ident,' ');
    cout << "(" << bdd.adjacency[x].var << "," << x << ")\n";

    print_bdd(bdd, bdd.adjacency[x].pos, ident+1);

}