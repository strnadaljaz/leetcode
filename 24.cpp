
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode();
        
        ListNode* prev_node = dummy;
        ListNode* curr_node = head;

        while (curr_node && curr_node->next) {
            prev_node->next = curr_node->next;
            curr_node->next = prev_node->next->next;
            prev_node->next->next = curr_node;
            prev_node = curr_node;
            curr_node = prev_node->next;
        }

        return dummy->next;
    }
};
