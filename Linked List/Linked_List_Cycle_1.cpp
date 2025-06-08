class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // move by 1
            fast = fast->next->next;     // move by 2

            if (slow == fast) {
                return true; // cycle detected
            }
        }

        return false; // no cycle
    }
};
