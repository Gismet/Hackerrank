#include <iostream>

// Singly Linked list node template
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode() : data(0), next(nullptr) {}
    SinglyLinkedListNode(int data) : data(data), next(nullptr) {}
};

// Utility Function
void PutNodeAtFront(SinglyLinkedListNode *&head, int val)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(val);
    newNode->next = head;
    head = newNode;
}

// Recursive Utility Function
void DisplayLinkedList(SinglyLinkedListNode *head)
{
    if (head)
    {
        std::cout << head->data << " ";
        DisplayLinkedList(head->next);
    }
}

int main()
{
    SinglyLinkedListNode *head = new SinglyLinkedListNode(5);
    PutNodeAtFront(head, 6);
    PutNodeAtFront(head, 4);

    // create two pointers
    SinglyLinkedListNode *prev = NULL;
    SinglyLinkedListNode *current = head;
    while (current)
    {
        // store the next node in the linked list
        SinglyLinkedListNode *temp = current->next;
        current->next = prev; // make the current node point back to prev
        prev = current;       // make prev current
        current = temp;       // move current to the next node which is stored in temp
    }

    DisplayLinkedList(prev);

    return 0;
}