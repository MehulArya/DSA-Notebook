/*
Time Complexity: O(n)
 - First pass: Traverse the list to create copy nodes → O(n)
 - Second pass: Set up next and random pointers → O(n)

Space Complexity: O(n)
 - Extra space used for hash map to store original → copied node mapping
*/

//Not the best way to solve in terms of Space Complexity

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Base case: If list is empty, return NULL
        if (head == NULL) return NULL;

        // Step 1: Create a mapping from original nodes to their copies
        unordered_map<Node*, Node*> mpp;

        Node* temp = head;
        while(temp != NULL){
            // Create a new node with the same value as the current node
            Node* newNode = new Node(temp->val);

            // Map original node to its copy
            mpp[temp] = newNode;

            // Move to the next node
            temp = temp->next;
        }

        // Step 2: Set the next and random pointers for the copied nodes
        Node* temp1 = head;
        while(temp1 != NULL){
            Node* copyNode = mpp[temp1]; // Get the copied node
            copyNode->next = mpp[temp1->next];     // Set next pointer
            copyNode->random = mpp[temp1->random]; // Set random pointer
            temp1 = temp1->next;
        }

        // Step 3: Return the head of the copied list
        return mpp[head];
    }
};
