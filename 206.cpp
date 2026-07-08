#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    ListNode* previous = NULL;
    ListNode* current = head;
    ListNode* next = head->next;

    while (next != NULL) {
        current->next = previous;
        previous = current;
        current = next;
        next = next->next;
    }

    current->next = previous;

    return current;
}

int main()
{
    cout << "Hello world";
    
    return 0;
}