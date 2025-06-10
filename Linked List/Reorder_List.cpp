class Solution {
public:
    // Helper function to reverse a linked list
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;     // Pointer to the current node
        ListNode* prev = NULL;     // Previous node starts as NULL
        ListNode* next;            // Temporary pointer to store next node

        // Iterate through the list and reverse the links
        while(curr != NULL){
            next = curr->next;     // Store next node
            curr->next = prev;     // Reverse the current node's pointer

            prev = curr;           // Move prev and curr one step forward
            curr = next;

            head = prev;           // Update head to the new front of the list
        }
        return head;               // Return the new head of the reversed list
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; // Edge case: list too short to reorder

        // Step 1: Find the middle of the linked list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;          // Move slow by 1
            fast = fast->next->next;    // Move fast by 2
        }
        // At this point, slow points to the middle node

        // Step 2: Reverse the second half of the list starting from slow
        ListNode* rev = reverseLL(slow);

        // Step 3: Merge the two halves alternately
        ListNode* temp = head;  // Start from the beginning of the original list

        while(rev != NULL){
            // Save the next nodes
            ListNode* revnext = rev->next;
            ListNode* tempnext = temp->next;

            // Insert rev node after temp
            temp->next = rev;
            rev->next = tempnext;

            // Move both pointers forward
            temp = tempnext;
            rev = revnext;
        }

        // Step 4: Ensure the final node points to NULL to avoid cycle
        if(temp) temp->next = NULL;
    }
};
