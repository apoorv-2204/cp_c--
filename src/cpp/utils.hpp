#pragma once

#include <string>
#include <vector>
namespace Utils
{
    void dbg(std::string msg, int zvar);
    void dbg_vector(std::vector<int> arr);
    std::vector<int> get_input_as_vector();
}