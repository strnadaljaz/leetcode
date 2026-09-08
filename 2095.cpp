
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *deleteMiddle(ListNode *head) {
        if (head->next == nullptr)
            return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev_slow = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        prev_slow->next = slow->next;

        return head;
    }
};
