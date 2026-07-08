struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// [1,2,3,4,5], n=2
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* p1, *p2;
        ListNode* previous;
        p1 = head;
        for (int i = 1; p1->next; ++i) {
            if (i == n)
                p2 = head;
            else if (i > n) 
                previous = p2;
                p2 = p2->next;
            p1 = p1->next;
        } 
        previous->next = p1;

        return head;
    }
};
