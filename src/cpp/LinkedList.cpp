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