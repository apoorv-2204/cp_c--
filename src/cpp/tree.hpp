#pragma once

#include <vector>
#include <queue>
#include <iostream>
#include "utils.hpp" // Assuming utils.hpp has necessary includes and declarations
namespace Tree
{
    class TreeNode
    {
    public:
        TreeNode *left;
        TreeNode *right;
        int val;

        TreeNode(int data);
    };

    void tree_main();
}
// #pragma once directive, which is a modern way to prevent double
//  inclusion. This is an alternative to the traditional include guards
//  (#ifndef, #define, and #endif).