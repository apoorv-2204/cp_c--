
#include "utils.hpp"
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

namespace Tree
{
    class TreeNode
    {
    public:
        TreeNode *left;
        TreeNode *right;
        int val;

        TreeNode(int data)
        {
            this->val = data;
            this->right = nullptr;
            this->left = nullptr;
        }
    };
    TreeNode *buildTreeCLI()
    {
        int data;
        cout << "Enter data" << endl;
        cin >> data;
        if (data == -1)
            return nullptr;
        TreeNode *newNode = new TreeNode(data);
        cout << "For Left  Node of " << data << endl;
        newNode->left = buildTreeCLI();
        cout << "For Right  Node of " << data << endl;
        newNode->right = buildTreeCLI();
        return newNode;
    }

    TreeNode *buildTree(std::vector<int> &arr)
    {
        int current_index = 0;
        if (arr.size() == 0)
            return nullptr;
        if (arr.size() == 1)
            return new TreeNode(arr[0]);
        return buildTree(arr, current_index);
    }
    // std::vector arr{20, 40, 60, -1, 80, -1, -1, -1, -1};

    TreeNode *buildTree(std::vector<int> &arr, int &current_index)
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

        TreeNode *newNode = new TreeNode(data);
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
    //         cout<< temp->val << " " <<endl;
    //     }
    // }
    void levelOrderTraversal(TreeNode *rootNode)
    {
        std::queue<TreeNode *> q;
        q.push(rootNode);
        q.push(nullptr);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == nullptr)
                std::cout << std::endl;
            q.push(nullptr);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            //    infinite loop pushing null pointer
            std::cout << temp->val << " ";
        }
    }

    void levelOrderTraversalWithLevels(TreeNode *rootNode)
    {
        std::queue<TreeNode *> q;
        q.push(rootNode);
        q.push(nullptr);

        while (!q.empty())
        {
            TreeNode *temp = q.front();

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
                std::cout << "..." << temp->val << "...";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }

    //  LNR left current node then right
    void inorder_traversal(TreeNode *rootNode)
    {
        if (rootNode == nullptr)
            return;
        inorder_traversal(rootNode->left);
        std::cout << rootNode->val << " ";
        inorder_traversal(rootNode->right);
    }

    //  NLR current node left  then right
    void preorder_traversal(TreeNode *rootNode)
    {
        if (rootNode == nullptr)
            return;
        std::cout << rootNode->val << " ";
        preorder_traversal(rootNode->left);
        preorder_traversal(rootNode->right);
    }

    //  LRN  left  then right current node
    void postorder_traversal(TreeNode *rootNode)
    {
        if (rootNode == nullptr)
            return;
        postorder_traversal(rootNode->left);
        postorder_traversal(rootNode->right);
        std::cout << rootNode->val << " ";
    }

    // recursion break down do for one and rest will follow
    // The maximum distance of any node from the rootNode. If a tree has only one node (the rootNode), the height is zero. The height of an empty tree is not defined.
    int height_of_tree(TreeNode *rootNode)
    {
        // calculate height of left subtree and right subtree
        // chose the max one and add one to it to include for rootNode
        if (rootNode == nullptr)
            return 0;
        int height = 1 + std::max(height_of_tree(rootNode->left), height_of_tree(rootNode->right));
        return height;
    }

    int rangeSumBST(TreeNode *root, int &low, int &high)
    {
        if (root == nullptr)
            return 0;
        int sum = 0;
        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
        }

        sum = sum + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        return sum;
    }

    // https://xlinux.nist.gov/dads/ imp
    // The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the rootNode.
    // The length of a path between two nodes is represented by the number of edges between them.
    int diameterOfBinaryTree(TreeNode *rootNode)
    {
        // bc root in null return 0
        if (rootNode == nullptr)
        {
            return 0;
        }
        int diameterOfCurrentNode = height(rootNode->left) + height(rootNode->right);

        return std::max({diameterOfCurrentNode, diameterOfBinaryTree(rootNode->left), diameterOfBinaryTree(rootNode->right)});
    }
    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        // check if current node is balacnced
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    bool isLeafNode(TreeNode *rootNode)
    {
        if (rootNode->left == nullptr && rootNode->right == nullptr)
            return true;
        return false;
    }

    bool hasPathSum(TreeNode *rootNode, int targetSum)
    {
        if (rootNode == nullptr)
            return false;
        int newTargetSum = targetSum - rootNode->val;
        if (newTargetSum == 0 && isLeafNode(rootNode))
            return true;
        return hasPathSum(rootNode->left, newTargetSum) || hasPathSum(rootNode->right, newTargetSum);
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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> path;
        ps(root, targetSum, path, res);
        return res;
    }

    TreeNode *kthAncestor(TreeNode *root, int &node, int &k)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == node)
        {
            k--;
            return root;
        }
        TreeNode *left = kthAncestor(root->left, node, k);
        TreeNode *right = kthAncestor(root->right, node, k);
        if ((left || right) && k == 0)
        {
            k = -1;
            return root;
        }
        if (left != nullptr)
        {
            k--;
            return left;
        }
        if (right != nullptr)
        {
            k--;
            return right;
        }
        return nullptr;
    }

    TreeNode *buildTreeFromPreOrderAndInorder(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> i_v_inorder_map;
        for (int i = 0; i < inorder.size(); i++)
            i_v_inorder_map[inorder[i]] = i;

        return dobuildTreeFromPreOrderAndInorder(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, i_v_inorder_map);
    }

    TreeNode *dobuildTreeFromPreOrderAndInorder(vector<int> &preorder, vector<int> &inorder, int startPO, int endPO, int startIO, int endIO, map<int, int> &i_v_inorder_map)
    {
        if (startPO > endPO || startIO > endIO)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[startPO]);
        // root->val = preorder[startPO];
        int indexOfRootInInorder = i_v_inorder_map[root->val];
        int sizeOfLSBT = indexOfRootInInorder - startIO;
        int sizeOfRSBT = endIO - indexOfRootInInorder;
        root->left = dobuildTreeFromPreOrderAndInorder(preorder, inorder, startPO + 1, startPO + sizeOfLSBT, startIO, indexOfRootInInorder - 1, i_v_inorder_map);
        root->right = dobuildTreeFromPreOrderAndInorder(preorder, inorder, startPO + sizeOfLSBT + 1, startPO + sizeOfLSBT + sizeOfRSBT, indexOfRootInInorder + 1, endIO, i_v_inorder_map);
        return root;
    }

    TreeNode *buildTreeFromInorderAndPostOrder(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> inorderVK;
        for (int i = 0; i < inorder.size(); i++)
            inorderVK[inorder[i]] = i;
        int postIndex = postorder.size() - 1;
        return dobuildTreeFromInorderAndPostOrder(inorder, postorder, postIndex, 0, inorder.size() - 1, inorderVK);
    }

    TreeNode *dobuildTreeFromInorderAndPostOrder(vector<int> &inorder, vector<int> &postorder, int &postIndex, int startIO, int endIO, map<int, int> &vkInorder)
    {
        if (postIndex < 0 || startIO > endIO)
            return nullptr;
        TreeNode *tn = new TreeNode(postorder[postIndex]);
        int indexOfNodeInInorderTraversal = vkInorder[postorder[postIndex]];

        postIndex--;
        tn->right = dobuildTreeFromInorderAndPostOrder(inorder, postorder, postIndex, indexOfNodeInInorderTraversal + 1, endIO, vkInorder);
        tn->left = dobuildTreeFromInorderAndPostOrder(inorder, postorder, postIndex, startIO, indexOfNodeInInorderTraversal - 1, vkInorder);
        return tn;
    }

    vector<int> *topView(TreeNode *root)
    {
        map<int, int> topView;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *front_node = p.first;
            int horizontalDistance = p.second;
            if (topView.find(front_node->val) == topView.end())
            {
                topView[front_node->val] = horizontalDistance;
            }
        }
    }

    void tree_main()
    {
        // std::vector arr{20, 40, 60, -1, 80, -1, -1, -1, -1};
        // std::vector arr{1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
        std::vector arr{10, 20, 30, -1, -1, 40, 60, -1, -1, 70, -1, -1, 50, -1, 90, 80, -1, -1, 100, -1, -1};

        TreeNode *root = buildTree(arr);
        levelOrderTraversalWithLevels(root);
    }

}
