#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int data);
};

Node* buildTree();
void levelOrderTraversal(Node* root);
void levelOrderTraversalWithLevels(Node* root);
void inorder_traversal(Node* root);
void preorder_traversal(Node* root);
void postorder_traversal(Node* root);
int height_of_tree(Node* root);