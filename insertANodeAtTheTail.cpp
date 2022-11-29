#include <iostream>

// definition of a singly linked list node
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

/*We can solve this problem in a few different ways
 * I take the approach of adding a dummy node at the head.
 * We can also use two pointers
 */

SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data)
{
    // create a dummy node and make it point to the head of linked list
    SinglyLinkedListNode *dummy = new SinglyLinkedListNode();
    dummy->next = head;
    // create a veriable to loop through the linked list
    SinglyLinkedListNode *loopPtr = new SinglyLinkedListNode();
    loopPtr = dummy;
    while (loopPtr->next != NULL)
    {
        loopPtr = loopPtr->next;
    }
    // create a new node to add at the tail
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode();
    newNode->data = data;
    // make at the tail(which is loopPtr) point to newNode
    loopPtr->next = newNode;
    // Since newNode now is the new tail node, it must point to NULL
    newNode->next = NULL;

    // And return the head of the linked list.
    return dummy->next;
}

int main()
{
    SinglyLinkedListNode *head = new SinglyLinkedListNode();
    head = NULL; // head is NULL
    head = insertNodeAtTail(head, 141);
    head = insertNodeAtTail(head, 302);
    head = insertNodeAtTail(head, 164);
    head = insertNodeAtTail(head, 530);
    head = insertNodeAtTail(head, 474);

    // to confirm the result, let's print the linked list(You can )

    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
