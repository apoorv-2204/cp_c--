#include "utils.hpp"
#include <algorithm> // for std::copy
#include <iterator>
#include <string>
#include <iostream>

namespace Utils
{
    void dbg(std::string msg, int zvar);
    void dbg_vector(std::vector<int> arr);
    std::vector<int> get_input_as_vector();

    void dbg(std::string msg, int zvar)
    {
        std::cout << "\n " + msg + " " << zvar << '\n';
    }

    void dbg_vector(std::vector<int> arr)
    {
        std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    }
    std::vector<int> get_input_as_vector()
    {
        int size = 0;
        std::cin >> size;
        std::vector<int> input_vec;

        while (size--)
        {
            int temp = 0;
            std::cin >> temp;
            input_vec.push_back(temp);
        }

        return input_vec;
    }
}