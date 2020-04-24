#pragma once

#include <vector>

using std::vector;
using std::pair;

struct Nand {

    using Edge = pair<bool, int>;

    int input_begin, input_end, output_begin, output_end;
    vector<Edge> adjacency;


    Nand(int input_begin, int input_end, int output_begin, int output_end)
    : input_begin(input_begin), input_end(input_end), output_begin(output_begin), output_end(output_end),
      adjacency(input_end - input_begin + output_end - output_begin)
    {
        
    }


};