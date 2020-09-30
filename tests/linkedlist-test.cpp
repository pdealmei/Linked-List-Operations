#include <gtest/gtest.h>
#include "linked-list-operations.hpp"


TEST(linkedlistoperations, inserting)
{
    Node* head = NULL;
    const int num_tests = 5;
    int test_values[num_tests] = {6 , -78 , 89 , 12, 30};
    
    for (int i = 0 ; i< 5 ; i++)
    {
        insertNode(&head,test_values[i]);
    }

    int index = num_tests - 1;
    while (head != NULL)
    {
        ASSERT_EQ(head->data,test_values[index]);
        head = head->next;
        --index;
    }
}

TEST(linkedlistoperations, deleting)
{
    Node* head = NULL;
    const int num_tests = 5;
    int test_values[num_tests] = {6 , -78 , 89 , 12, 30};
    
    for (int i = 0 ; i< 5 ; i++)
    {
        insertNode(&head,test_values[i]);
    }

    // delete two elements
    deleteNode(&head, 0);  
    deleteNode(&head, 2);


    // The resulting list should be {12, 89, 6}
    ASSERT_EQ(head->data,test_values[3]);
    head = head->next;
    ASSERT_EQ(head->data,test_values[2]);
    head = head->next;
    ASSERT_EQ(head->data,test_values[0]);

}