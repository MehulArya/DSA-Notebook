class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;  // This will store the preorder traversal result

        if(root == NULL) return preorder;  // If the tree is empty, return an empty result

        stack<TreeNode*> st;  // Stack to simulate recursive function calls (LIFO)
        st.push(root);        // Start with the root node

        while(!st.empty()) {  // Loop until all nodes are processed
            root = st.top();  // Get the top node from the stack
            st.pop();         // Remove it from the stack

            preorder.push_back(root->val);  // Visit the node (preorder: Root -> Left -> Right)

            // Push right child first so that left child is processed first (stack is LIFO)
            if(root->right != NULL) st.push(root->right);

            // Push left child to stack
            if(root->left != NULL) st.push(root->left);
        }

        return preorder;  // Return the final preorder traversal result
    }
};
