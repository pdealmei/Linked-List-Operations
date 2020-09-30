#include "linked-list-operations.hpp"

void insertNode(Node** head , int new_data)
{
    Node* new_node = (Node*) malloc(sizeof(Node*));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void deleteNode(Node** head, int index)
{

    if(*head == NULL)
    {
        return;
    }
    Node* temp = *head;

    // In this case we want to remove the head
    if(index == 0)
    {
        *head = temp ->next; // Assign the head to the next element
        free(temp); // Remove the head;
        return;
    }

    for(int i = 0 ; i<index-1 && temp!=NULL ; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        // We reached the end of the list
        return;
    }
    
    Node* next = temp->next->next;
    free(temp->next); //Delete the desired element
    temp->next = next; // Link to the rest of the list
}

void printLinkedList(Node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}