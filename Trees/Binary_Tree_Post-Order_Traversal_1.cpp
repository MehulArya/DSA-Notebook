class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;  // This vector will store the postorder traversal result

        if(root == NULL) return postorder;  // If the tree is empty, return an empty result

        stack<TreeNode*> st1, st2;  // Two stacks: st1 for processing nodes, st2 for reverse postorder

        st1.push(root);  // Start traversal with the root node

        // First phase: use st1 to visit nodes in Root → Right → Left order
        while(!st1.empty()) {
            TreeNode* node = st1.top();  // Get the top node from st1
            st1.pop();                   // Remove the node from st1
            st2.push(node);              // Push the node into st2

            // Push left child first so it gets processed after the right child
            if(node->left != NULL) st1.push(node->left);

            // Push right child
            if(node->right != NULL) st1.push(node->right);
        }

        // Second phase: pop all nodes from st2 to get Left → Right → Root order
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val);  // Add node value to result
            st2.pop();                            // Remove node from st2
        }

        return postorder;  // Return the final postorder traversal
    }
};
