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
    int _not_(int x) {
        int out = new_vertex();
        adjacency[x].emplace_back(false, out);
        return out;
    }

    int _nand_(const vector<int> & inputs) {
        return _not_(_and_(inputs));
    }

    int _nor_(const vector<int> & inputs) {
        int out = new_vertex();
        for(int i : inputs) {
            adjacency[i].emplace_back(false, out);
        }
        return out;
    }

    int _or_(const vector<int> & inputs) {
        return _not_(_nor_(inputs));
    }


    int _xor2_(int x, int y) {
        int aux1 = _or_({x, y});
        int aux2 = _nand_({x, y});
        return _and_({x, y});
    }

    int _xor_(const vector<int> & inputs) {
        int x = inputs[0];
        for(int i = 1; i < inputs.size(); ++i) {
            x = _xor2_(x, inputs[i]);
        }
        return x;
    }

};