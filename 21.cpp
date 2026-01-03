#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void izpisiListNode(ListNode* list) {
    while (list != nullptr) {
        std::cout << list->val;
        list = list->next;
    }
    std::cout << std::endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = list1;

    while (list1->next != nullptr) {
        list1 = list1->next;
    }

    list1->next = list2;

    return head;    
}

int main() {
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    ListNode* l3 = new ListNode();
    ListNode* l4 = new ListNode();
    ListNode* l5 = new ListNode();
    ListNode* l6 = new ListNode();

    l1->val = 1;
    l2->val = 2;
    l3->val = 4;
    l4->val = 1;
    l5->val = 3;
    l6->val = 4;

    l1->next = l2;
    l2->next = l3;
    l3->next = nullptr;
    l4->next = l5;
    l5->next = l6;
    l6->next = nullptr;

    ListNode* merged = mergeTwoLists(l1, l4);
    izpisiListNode(merged);

    return 0;
}