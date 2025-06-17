class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;        // Stack to store nodes for traversal
        vector<int> inorder;        // Vector to store the inorder traversal result
        TreeNode* node = root;      // Start traversal from the root

        while(true) {
            if(node != NULL) {
                // If the current node is not null, push it onto the stack
                // and move to its left child
                st.push(node);
                node = node->left;
            }
            else {
                // If the stack is empty, traversal is complete
                if(st.empty() == true) break;

                // Node is null, so backtrack using the stack
                node = st.top();     // Get the node from the top of the stack
                st.pop();            // Remove it from the stack

                inorder.push_back(node->val);  // Visit the node

                node = node->right;  // Move to the right subtree
            }
        }

        return inorder;  // Return the final inorder traversal
    }
};
