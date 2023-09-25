#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node()
    {
        this->next = nullptr;
        this->data = 0;
    }

    Node(int data)
    {
        this->next = nullptr;
        this->data = data;
    }

    Node(Node &other)
    {
        // ->is applied to poitner type
        this->next = other.next;
        this->data = other.data;
    }
};

class SLL
{
    Node *head;
    Node *tail;

    SLL(int data)
    {
        head = tail = new Node(data);
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }

}

int
main()
{
}
class Node
{
public:
    Node *next;
    int data;
    Node *prev;

    Node()
    {
        this->next = nullptr;
        this->data = 0;
    }

    Node(int data)
    {
        this->next = nullptr;
        this->data = data;
    }

    Node(Node &other)
    {
        // ->is applied to poitner type
        this->next = other.next;
        this->data = other.data;
    }
};

class SLL
{
    Node *head;
    Node *tail;

public:
    SLL(int data)
    {
        head = tail = new Node(data);
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};
#include <iostream>
// using namespace std;

// class Node
// {
// public:
//         int data;
//         Node *next;

//         Node()
//         {
//                 this->data = 0;
//                 this->next = NULL;
//         }
//         Node(int data)
//         {
//                 this->data = data;
//                 this->next = NULL;
//         }
// };

// // I want to insert a node right at the head of Linked List
// void insertAtHead(Node *&head, Node *&tail, int data)
// {
//         // check for Empty LL
//         if (head == NULL)
//         {
//                 Node *newNode = new Node(data);
//                 head = newNode;
//                 tail = newNode;
//         }
//         else
//         {
//                 // step1:
//                 Node *newNode = new Node(data);
//                 // step2:
//                 newNode->next = head;
//                 // step3:
//                 head = newNode;
//         }
// }
// // I want to insert a node right at the end of LINKED LIST
// void insertAtTail(Node *&head, Node *&tail, int data)
// {
//         if (head == NULL)
//         {
//                 Node *newNode = new Node(data);
//                 head = newNode;
//                 tail = newNode;
//                 return;
//         }
//         // step1: creatae a node
//         Node *newNode = new Node(data);
//         // step2: connect woth tail ndoe
//         tail->next = newNode;
//         // step3: update tail;
//         tail = newNode;
// }
// void print(Node *head)
// {

//         Node *temp = head;
//         while (temp != NULL)
//         {
//                 cout << temp->data << " ";
//                 temp = temp->next;
//         }
// }

// int findLength(Node *&head)
// {
//         int len = 0;
//         Node *temp = head;
//         while (temp != NULL)
//         {
//                 temp = temp->next;
//                 len++;
//         }
//         return len;
// }

// void insertAtPosition(int data, int position, Node *&head, Node *&tail)
// {
//         if (head == NULL)
//         {
//                 Node *newNode = new Node(data);
//                 head = newNode;
//                 tail = newNode;
//                 return;
//         }
//         // step1: find the position: prev & curr;

//         if (position == 0)
//         {
//                 insertAtHead(head, tail, data);
//                 return;
//         }

//         int len = findLength(head);

//         if (position >= len)
//         {
//                 insertAtTail(head, tail, data);
//                 return;
//         }
//         // ste1:find prev and curr
//         int i = 1;
//         Node *prev = head;
//         while (i < position)
//         {
//                 prev = prev->next;
//                 i++;
//         }
//         Node *curr = prev->next;

//         // step2;
//         Node *newNode = new Node(data);

//         // step3:
//         newNode->next = curr;

//         // step4:
//         prev->next = newNode;
// }

// int main()
// {

//         Node *head = NULL;
//         Node *tail = NULL;
//         insertAtHead(head, tail, 20);
//         insertAtHead(head, tail, 50);
//         insertAtHead(head, tail, 60);
//         insertAtHead(head, tail, 90);
//         insertAtTail(head, tail, 77);

//         print(head);
//         cout << endl;
//         // cout << "head: " << head -> data << endl;
//         // cout << "tail: " << tail->data << endl;

//         insertAtPosition(101, 5, head, tail);
//         cout << "Printing after insert at position call" << endl;
//         print(head);
//         cout << endl;
//         cout << "head: " << head->data << endl;
//         cout << "tail: " << tail->data << endl;

//         return 0;
// }