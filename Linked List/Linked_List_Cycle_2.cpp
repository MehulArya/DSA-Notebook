class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Create a hash set to store visited node addresses
        unordered_set<ListNode*> value;

        // Start traversal from the head
        ListNode* temp = head;

        // Traverse the linked list
        while (temp != NULL) {
            // If current node is already in the set, a cycle exists
            if (value.find(temp) != value.end()) {
                return true;
            } else {
                // Otherwise, insert the node into the set and move to the next
                value.insert(temp);
                temp = temp->next;
            }
        }

        // If traversal ends (no cycle detected), return false
        return false;
    }
};