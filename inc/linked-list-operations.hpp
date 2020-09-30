#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


void insertNode(Node** head , int new_data);
void deleteNode(Node** head , int index);
void printLinkedList(Node* head);