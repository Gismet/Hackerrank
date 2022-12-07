#include <iostream>
#include <vector>

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode(int data) : data(data), next(nullptr) {}
    SinglyLinkedListNode *next;
};

void printLinkedList(SinglyLinkedListNode *head)
{
    if (head)
    {
        std::cout << head->data << " ";
        printLinkedList(head->next);
    }
}

SinglyLinkedListNode *mergeLists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *resultHead = NULL; // this will be merged linked list

    // pointers to the  linked lists to traverse them
    SinglyLinkedListNode *head1Pointer = head1;
    SinglyLinkedListNode *head2Pointer = head2;
    std::vector<SinglyLinkedListNode *> nodes;

    // push them to the vector ( I used it as a stack)
    while (head1Pointer && head2Pointer)
    {
        if (head1Pointer->data < head2Pointer->data)
        {
            nodes.push_back(head1Pointer);
            head1Pointer = head1Pointer->next;
        }
        else
        {
            nodes.push_back(head2Pointer);
            head2Pointer = head2Pointer->next;
        }
    }

    // check if any of the linked lists fell off the end

    while (head1Pointer)
    {
        nodes.push_back(head1Pointer);
        head1Pointer = head1Pointer->next;
    }

    while (head2Pointer)
    {
        nodes.push_back(head2Pointer);
        head2Pointer = head2Pointer->next;
    }

    // bulding result linked list from the end
    int i = nodes.size() - 1;
    while (i >= 0)
    {
        nodes[i]->next = resultHead;
        resultHead = nodes[i];
        i--;
    }
    return resultHead;
}

int main()
{
    SinglyLinkedListNode *headA = new SinglyLinkedListNode(1);
    headA->next = new SinglyLinkedListNode(3);
    headA->next->next = new SinglyLinkedListNode(5);

    SinglyLinkedListNode *headB = new SinglyLinkedListNode(3);
    headB->next = new SinglyLinkedListNode(7);
    headB->next->next = new SinglyLinkedListNode(9);

    SinglyLinkedListNode *resultHead = mergeLists(headA, headB);

    printLinkedList(resultHead);

    return 0;
}