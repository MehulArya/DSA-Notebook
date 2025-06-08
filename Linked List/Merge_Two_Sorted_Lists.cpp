class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;  // Pointer for list1
        ListNode* temp2 = list2;  // Pointer for list2
        ListNode new_head;        // Dummy node for new list
        ListNode* temp3 = &new_head;  // Pointer to build the merged list

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {  // Choose smaller node
                temp3->next = temp1;
                temp1 = temp1->next;
            } else {
                temp3->next = temp2;
                temp2 = temp2->next;
            }
            temp3 = temp3->next;  // Move pointer forward
        }

        while (temp1 != NULL) { // Attach remaining list1
            temp3->next = temp1;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) { // Attach remaining list2
            temp3->next = temp2;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }

        return new_head.next;  // Return merged list head
    }
};
