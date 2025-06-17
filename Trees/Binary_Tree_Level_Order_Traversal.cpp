class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;  // This will store the final result (level-wise node values)

        if(root == NULL) return ans;  // If the tree is empty, return an empty result

        queue<TreeNode*> q;  // Queue to perform level order traversal (BFS)
        q.push(root);        // Start with the root node

        while(!q.empty()) {  // Traverse while there are nodes in the queue
            vector<int> levels;     // Temporary vector to store values at the current level
            int size = q.size();    // Number of nodes at the current level

            for(int i = 0; i < size; i++) {   // Process all nodes at the current level
                TreeNode* node = q.front();   // Get the front node from the queue
                q.pop();                      // Remove it from the queue

                // If left child exists, add it to the queue
                if(node->left != NULL) q.push(node->left);

                // If right child exists, add it to the queue
                if(node->right != NULL) q.push(node->right);

                levels.push_back(node->val);  // Add the current node's value to the level list
            }

            ans.push_back(levels);  // Add the current level's values to the final result
        }

        return ans;  // Return the level-order traversal result
    }
};
