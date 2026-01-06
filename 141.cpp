#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {

    ListNode* walker = head;
    ListNode* runner = head;

    while (runner != NULL && runner->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;

        if (runner == walker) return true;
    }

    return false;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    head->next = second;
    
    cout << hasCycle(head);
    
    return 0;
}