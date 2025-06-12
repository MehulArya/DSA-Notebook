class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_head = new ListNode(0); // Dummy node to simplify edge cases
        ListNode* res = new_head;             // Pointer to build the result list
        int carry = 0;                        // Initialize carry to 0

        while(l1 != NULL || l2 != NULL){      // Loop until both lists are fully traversed
            int x = 0, y = 0;                 // Default values if one list is shorter

            if(l1 != NULL){
                x = l1->val;                  // Extract value from l1 if available
            }
            if(l2 != NULL){
                y = l2->val;                  // Extract value from l2 if available
            }

            int sum = x + y + carry;          // Sum the digits along with the carry
            carry = sum / 10;                 // Calculate new carry
            ListNode* result = new ListNode(sum % 10); // Create node with current digit
            res->next = result;               // Link the new node to the result list
            res = res->next;                  // Move the result pointer forward

            if(l1 != NULL) l1 = l1->next;     // Move to the next node in l1
            if(l2 != NULL) l2 = l2->next;     // Move to the next node in l2
        }

        if(carry > 0){
            res->next = new ListNode(carry);  // If there's leftover carry, add it as a node
        }

        return new_head->next;                // Return the real head (skip dummy)
    }
};
