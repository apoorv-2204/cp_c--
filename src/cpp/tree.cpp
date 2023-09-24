
#include <utils.hpp>


// class Tree{
//     using namespace std;
//     public: 
//         Node* root;

//     buildTree(vector<int> & ){


        

//     } 
// }

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data){
        this-> data=data    ;
        this-> right = nullptr;
        this -> left=nullptr;
    } 
};

// or read array to create a tree
Node* buildTree(){
    int data;
    cout<< "Enter data"<<endl;
    cin>> data;
    
    if(data==-1) return nullptr;
    Node* newNode= new Node(data);

    cout<< "For Left  Node of "<<data<<endl;
    newNode-> left = buildTree();

    cout<< "For Right  Node of "<<data<<endl;
    newNode-> right= buildTree();

    return newNode;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp= q.front();
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right)  q.push(temp->right);
    //    infinite loop pushing null pointer
        cout<< temp->data << " " <<endl;
    }
}


void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp= q.front();
        q.pop();
        if(temp ==nulptr ) cout<< endl; q.push(nullptr);
        if(temp->left) q.push(temp->left);
        if(temp->right)  q.push(temp->right);
    //    infinite loop pushing null pointer
        cout<< temp->data << " " ;
    }
}

int tree_main()
{
    Node * root = buildTree();
    levelOrderTraversal(root);

    return 0;
}



Node* buildTree(){
    int data;
    cout<< "Enter data"<<endl;
    cin>> data;
    
    if(data==-1) return nullptr;
    Node* newNode= new Node(data);

    cout<< "For Left  Node of "<<data<<endl;
    newNode-> left = buildTree();

    cout<< "For Right  Node of "<<data<<endl;
    newNode-> right= buildTree();

    return newNode;
}

void levelOrderTraversalWithLevels(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp= q.front();

        q.pop();

        if(temp ==nullptr ) {

            cout<< endl;

        if(!q.empty()) q.push(nullptr);//imp

        }else{
        if(temp->left) q.push(temp->left);
        if(temp->right)  q.push(temp->right);
    //    infinite loop pushing null pointer
        cout<< temp->data << " " ;

        }
    }
}

//  LNR left current node then right
void inorder_traversal(Node * root){
    if(root ==nullptr) return;
    inorder_traversal(root-> left);
    cout << root-> data<< " ";
    inorder_traversal(root-> right);
}

//  NLR current node left  then right
void preorder_traversal(Node * root){
    if(root ==nullptr) return;
    cout << root-> data<< " ";
    preorder_traversal(root-> left);
    preorder_traversal(root-> right);
}

//  LRN  left  then right current node
void postorder_traversal(Node * root){
    if(root ==nullptr) return;
    postorder_traversal(root-> left);
    postorder_traversal(root-> right);
    cout << root-> data<< " ";
}
// recursion break down do for one and rest will follow
// The maximum distance of any node from the root. If a tree has only one node (the root), the height is zero. The height of an empty tree is not defined.
int height_of_tree(Node * root) {
    // calculate height of left subtree and right subtree
    // chose the max one and add one to it to include for root
    if(root==nullptr) return 0;
    int height =1+ max(height_of_tree(root->left),height_of_tree(root->right));
    return height;
}

// https://xlinux.nist.gov/dads/ imp
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.
// int diameter_of_tree(Node * root){
   
// }

