#include <iostream>
#include <stack>

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode(int data) : data(data), next(nullptr) {}
    SinglyLinkedListNode *next;
};

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *llist)
{
    if (llist == NULL || llist->next == NULL)
        return llist;
    SinglyLinkedListNode *prev;
    prev = llist;
    SinglyLinkedListNode *loopPtr = llist->next;
    while (loopPtr)
    {
        if (prev->data != loopPtr->data)
        {
            prev->next = loopPtr;
            prev = prev->next;
            loopPtr = loopPtr->next;
        }
        else
        {
            loopPtr = loopPtr->next;
        }
    }
    prev->next = NULL;
    return llist;
}

void printLinkedList(SinglyLinkedListNode *head)
{
    if (head)
    {
        std::cout << head->data << " ";
        printLinkedList(head->next);
    }
}

int main()
{
    // 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4 ====> 1 -> 2 -> 3 -> 4
    SinglyLinkedListNode *head = new SinglyLinkedListNode(1);
    head->next = new SinglyLinkedListNode(2);
    head->next->next = new SinglyLinkedListNode(2);
    head->next->next->next = new SinglyLinkedListNode(3);
    head->next->next->next->next = new SinglyLinkedListNode(3);
    head->next->next->next->next->next = new SinglyLinkedListNode(4);
    head->next->next->next->next->next->next = new SinglyLinkedListNode(4);

    printLinkedList(removeDuplicates(head));

    return 0;
}