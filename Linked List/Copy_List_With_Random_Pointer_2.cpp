/*
Time Complexity: O(n)
 - First pass: Traverse the list to create copy nodes → O(n)
 - Second pass: Set up next and random pointers → O(n)

Space Complexity: O(1)
 - Extra space used for hash map is removed.
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Create a copy of each node and insert it next to the original node
        // Example: A -> B -> C becomes A -> A' -> B -> B' -> C -> C'
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);   // Create copy of current node
            copyNode->next = temp->next;            // Link it to the next original node
            temp->next = copyNode;                  // Insert copy after original
            temp = copyNode->next;                  // Move to the next original node
        }

        // Step 2: Set the random pointers of the copied nodes
        Node* temp1 = head;
        while(temp1 != NULL){
            if(temp1->random == NULL){
                temp1->next->random = NULL;         // If original random is NULL
            } else {
                temp1->next->random = temp1->random->next; // Copy's random is original's random's copy
            }
            temp1 = temp1->next->next;              // Move to the next original node
        }

        // Step 3: Separate the interleaved list into original and copied list
        Node* temp2 = head;
        Node* dummy = new Node(0);                  // Dummy head for the copied list
        Node* res = dummy;

        while(temp2 != NULL){
            res->next = temp2->next;                // Add the copied node to the result list
            temp2->next = temp2->next->next;        // Restore the original list
            res = res->next;                        // Move forward in the result list
            temp2 = temp2->next;                    // Move forward in the original list
        }

        return dummy->next;                         // Return the head of the copied list
    }
};
