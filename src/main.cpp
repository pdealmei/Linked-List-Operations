
#include "linked-list-operations.hpp"



int main()
{
    Node* head =NULL;

    // Insert
    insertNode(&head, 8);
    insertNode(&head, 57);
    insertNode(&head, 12);
    insertNode(&head, 20);
    
    cout<<"The list before deleting an element is:"<<endl;
    printLinkedList(head);
    
    deleteNode(&head,2);
    cout<<"The list after deleting an element is:"<<endl;
    printLinkedList(head);
    return 0;
}

