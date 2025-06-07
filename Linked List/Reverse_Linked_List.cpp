class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; // Create Pointer, pointing the head
        ListNode* prev = NULL; // Create pointer just behind the curr pointer
        ListNode* next; // Create a Pointer just ahead of curr
        while(curr != NULL){ // Run the loop until curr reaches NULL
            next = curr->next; // Assign the address of next to next of curr
            curr->next = prev; // Assign the direction of curr to previous now (Reverse the direction)
            prev = curr; // Shift the pointers: 1. curr becomes Prev
            curr = next; // 2. next becomes curr
            head = prev; // and assign head as prev because the end node of the linked list when curr reaches NULL, is prev
        }
        return head; // return the head
    }
};