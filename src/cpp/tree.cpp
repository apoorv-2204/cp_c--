
#include "utils.hpp"
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

class Tree
{
public:
    Node *root;
    // Node* buildTree(){
    //     int data;
    //     cout<< "Enter data"<<endl;
    //     cin>> data;
    //     if(data==-1) return nullptr;
    //     Node* newNode= new Node(data);
    //     cout<< "For Left  Node of "<<data<<endl;
    //     newNode-> left = buildTree();
    //     cout<< "For Right  Node of "<<data<<endl;
    //     newNode-> right= buildTree();`
    //     return newNode;
    // }
    // std::vector arr{20, 40, 60, -1, 80, -1, -1, -1, -1};

    static Node *buildTree(std::vector<int> &arr)
    {
        int current_index = 0;
        if (arr.size() == 0)
            return nullptr;
        if (arr.size() == 1)
            return new Node(arr[0]);
        return buildTree(arr, current_index);
    }
    // std::vector arr{20, 40, 60, -1, 80, -1, -1, -1, -1};

    static Node *buildTree(std::vector<int> &arr, int &current_index)
    {
        // Utils::dbg("buildTree", current_index);

        if (current_index >= arr.size())
            return nullptr;
        int data = arr[current_index];

        if (data == -1)
        {
            current_index++;
            return nullptr;
        }

        Node *newNode = new Node(data);
        current_index++;
        newNode->left = buildTree(arr, current_index);
        newNode->right = buildTree(arr, current_index);
        return newNode;
    }

    // void levelOrderTraversal(Node* root){
    //     queue<Node*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         Node* temp= q.front();
    //         q.pop();
    //         if(temp->left) q.push(temp->left);
    //         if(temp->right)  q.push(temp->right);
    //     //    infinite loop pushing null pointer
    //         cout<< temp->data << " " <<endl;
    //     }
    // }
    static void levelOrderTraversal(Node *rootNode)
    {
        std::queue<Node *> q;
        q.push(rootNode);
        q.push(nullptr);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == nullptr)
                std::cout << std::endl;
            q.push(nullptr);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            //    infinite loop pushing null pointer
            std::cout << temp->data << " ";
        }
    }

    static void levelOrderTraversalWithLevels(Node *rootNode)
    {
        std::queue<Node *> q;
        q.push(rootNode);
        q.push(nullptr);

        while (!q.empty())
        {
            Node *temp = q.front();

            q.pop();

            if (temp == nullptr)
            {
                std::cout << "..." << std::endl;
                if (!q.empty())
                {
                    q.push(nullptr);
                } // imp
            }
            else
            {
                std::cout << "..." << temp->data << "...";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }

    //  LNR left current node then right
    static void inorder_traversal(Node *rootNode)
    {
        if (rootNode == nullptr)
            return;
        inorder_traversal(rootNode->left);
        std::cout << rootNode->data << " ";
        inorder_traversal(rootNode->right);
    }

    //  NLR current node left  then right
    static void preorder_traversal(Node *rootNode)
    {
        if (rootNode == nullptr)
            return;
        std::cout << rootNode->data << " ";
        preorder_traversal(rootNode->left);
        preorder_traversal(rootNode->right);
    }

    //  LRN  left  then right current node
    static void postorder_traversal(Node *rootNode)
    {
        if (rootNode == nullptr)
            return;
        postorder_traversal(rootNode->left);
        postorder_traversal(rootNode->right);
        std::cout << rootNode->data << " ";
    }

    // recursion break down do for one and rest will follow
    // The maximum distance of any node from the rootNode. If a tree has only one node (the rootNode), the height is zero. The height of an empty tree is not defined.
    static int height_of_tree(Node *rootNode)
    {
        // calculate height of left subtree and right subtree
        // chose the max one and add one to it to include for rootNode
        if (rootNode == nullptr)
            return 0;
        int height = 1 + std::max(height_of_tree(rootNode->left), height_of_tree(rootNode->right));
        return height;
    }

    int rangeSumBST(Node *root, int &low, int &high)
    {
        if (root == nullptr)
            return 0;
        int sum = 0;
        if (root->data >= low && root->data <= high)
        {
            sum += root->data;
        }

        sum = sum + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        return sum;
    }

    // https://xlinux.nist.gov/dads/ imp
    // The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the rootNode.
    // The length of a path between two nodes is represented by the number of edges between them.
    int diameterOfBinaryTree(Node *rootNode)
    {
        // bc root in null return 0
        if (rootNode == nullptr)
        {
            return 0;
        }
        int diameterOfCurrentNode = height(root->left) + height(root->right);

        return std::max({diameterOfCurrentNode, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }
    int height(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

    bool isBalanced(Node *root)
    {
        if (root == nullptr)
            return true;
        // check if current node is balacnced
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode *rootNode, int targetSum)
{
    if (rootNode == nullptr)
        return false;
    int newTargetSum = targetSum - rootNode->val;
    if (newTargetSum == 0 && isLeafNode(rootNode))
        return true;
    return hasPathSum(rootNode->left, newTargetSum) || hasPathSum(rootNode->right, newTargetSum);
}
bool isLeafNode(TreeNode *rootNode)
{
    if (rootNode->left == nullptr && rootNode->right == nullptr)
        return true;
    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // bc root ==nullptr return nullptr
    // is currentnode equal to any of node p and q is so return that node pointer
    // else search in left and search in right

    if (root == nullptr)
        return nullptr;
    if (root == p)
        return p;
    if (root == q)
        return q;

    TreeNode *leftRes = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightRes = lowestCommonAncestor(root->right, p, q);

    if (leftRes != nullptr && rightRes != nullptr)
        return root;
    if (leftRes != nullptr)
        return leftRes;
    if (rightRes != nullptr)
        return rightRes;
    return nullptr;
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> res;
    vector<int> path;
    ps(root, targetSum, path, res);
    return res;
}

void ps(TreeNode *root, int targetSum, vector<int> path, vector<vector<int>> &res)
{
    if (root == nullptr)
        return;

    int newTargetSum = targetSum - root->val;
    path.push_back(root->val);

    if (newTargetSum == 0 && root->left == nullptr && root->right == nullptr)
    {
        res.push_back(path);
        return;
    }

    ps(root->left, newTargetSum, path, res);
    ps(root->right, newTargetSum, path, res);
}



void tree_main()
{
    // std::vector arr{20, 40, 60, -1, 80, -1, -1, -1, -1};
    std::vector arr{
        10,
        60,
        80,
        -1,
        -1,
        20,
        70,
        -1,
        -1,
        40,
        -1,
        -1, 30, -1, 50, -1, -1};

    Node *root = Tree::buildTree(arr);
    Tree::levelOrderTraversalWithLevels(root);

    Utils::dbg("diameter", diameter_of_tree(root));
}
