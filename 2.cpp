#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

void izpisiListNode(ListNode* list) {
    while (list != nullptr) {
        cout << list->val;
        list = list->next;
    }
    cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
    ListNode* dummy = new ListNode();
    ListNode* previous = dummy;
    
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry) {
        int sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        ListNode* current = new ListNode();
        current->val = sum % 10;
        carry = sum / 10;
        previous->next = current;
        previous = current;
    }

    return dummy->next;
}

int main()
{
    ListNode k1, k2, k3, k4, k5, k6;
    k1.val = 2;
    k2.val = 4;
    k3.val = 3;
    k4.val = 5;
    k5.val = 6;
    k6.val = 4;

    k1.next = &k2;
    k2.next = &k3;
    k3.next = nullptr;
    
    k4.next = &k5;
    k5.next = &k6;
    k6.next = nullptr;

    ListNode* l1 = &k1;
    ListNode* l2 = &k4;

    izpisiListNode(l1);
    izpisiListNode(l2);

    ListNode* sum = addTwoNumbers(l1, l2);

    izpisiListNode(sum);

    return 0;
}