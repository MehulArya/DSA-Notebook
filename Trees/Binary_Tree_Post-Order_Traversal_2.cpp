class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        // If the tree is empty, return an empty result
        if(root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        // Continue while there are unprocessed nodes or a current node to explore
        while(!st.empty() || curr != NULL) {

            if(curr != NULL) {
                // Go as left as possible, pushing all nodes along the path
                st.push(curr);
                curr = curr->left;
            }
            else {
                // At this point, we have no left child to process.
                // Peek the right child of the top node in the stack
                TreeNode* temp = st.top()->right;

                if(temp == NULL) {
                    // If there's no right child, we can process the top node
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);

                    // Now keep popping and processing nodes while the current node
                    // is the right child of the top of the stack. This means the
                    // right subtree has been fully visited.
                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                } else {
                    // If there is a right child, process it next
                    curr = temp;
                }
            }
        }

        return postorder;
    }
};
