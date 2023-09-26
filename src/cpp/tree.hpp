#pragma once

#include <vector>
#include <queue>
#include <iostream>
#include "utils.hpp" // Assuming utils.hpp has necessary includes and declarations

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data);
};

class Tree
{
public:
    Node *root;

    static Node *buildTree(std::vector<int> &arr);
    static Node *buildTree(std::vector<int> &arr, int &current_index);
    static void levelOrderTraversal(Node *rootNode);
    static void levelOrderTraversalWithLevels(Node *rootNode);
    static void inorder_traversal(Node *rootNode);
    static void preorder_traversal(Node *rootNode);
    static void postorder_traversal(Node *rootNode);
    static int height_of_tree(Node *rootNode);
};

void tree_main();

// #pragma once directive, which is a modern way to prevent double
//  inclusion. This is an alternative to the traditional include guards
//  (#ifndef, #define, and #endif).