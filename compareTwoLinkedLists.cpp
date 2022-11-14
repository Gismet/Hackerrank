#include <iostream>

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode() : data(0), next(nullptr) {}
    SinglyLinkedListNode(int val) : data(val), next(nullptr) {}
};

// Utility function
void AddNodeAtFront(SinglyLinkedListNode *&head, int val)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(val);
    newNode->next = head;
    head = newNode;
}

// Iterative Utility function
void PrintOutLinkedListNodes(SinglyLinkedListNode *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}

bool compare_lists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    // As long as none of head1 and head2 is NULL, do
    while (head1 && head2)
    {
        // check if data in nodes are equal, if not return 0
        if (head1->data != head2->data)
            return 0;
        // otherwise, move to the next node
        head1 = head1->next;
        head2 = head2->next;
    }
    // check if both head1 and head2 are NULL, if yes, Then they are of same length
    // and since we iterated through both linked list, we can return 1
    if (head1 == NULL && head2 == NULL)
    {
        return 1;
    }
    else // otherwise they are not even of same length , return 0
    {
        return 0;
    }
}

int main()
{
    SinglyLinkedListNode *head1 = new SinglyLinkedListNode(1);
    AddNodeAtFront(head1, 2);
    AddNodeAtFront(head1, 3);

    SinglyLinkedListNode *head2 = new SinglyLinkedListNode(1);
    AddNodeAtFront(head2, 2);

    // compare if h1 and h2 are equal
    std::cout << compare_lists(head1, head2);

    return 0;
}