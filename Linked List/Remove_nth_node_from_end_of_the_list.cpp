class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count total number of nodes
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        // Step 2: Edge case - if the node to be removed is the head itself
        // (i.e., n == total length of list)
        if(count == n){
            ListNode* new_head = head->next; // Move head forward
            delete head;                     // Delete old head
            return new_head;                 // Return new head
        }

        // Step 3: Calculate the position of the node *before* the one to be deleted
        int res = count - n;
        ListNode* temp1 = head;

        // Move temp1 to the (count - n - 1)th node (i.e., one before the one to delete)
        while(temp1 != NULL){
            res--;
            if(res == 0){
                break;
            }
            temp1 = temp1->next;
        }

        // Step 4: Delete the nth node from end
        ListNode* delnode = temp1->next;         // Node to be deleted
        temp1->next = temp1->next->next;         // Bypass the deleted node
        delete delnode;                          // Free memory

        // Step 5: Return the head of the updated list
        return head;
    }
};
