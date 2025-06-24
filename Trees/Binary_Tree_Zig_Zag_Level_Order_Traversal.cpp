class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result; // If tree is empty, return empty result

        bool flag = true; // Direction flag: true for left-to-right, false for right-to-left
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at current level
            vector<int> row(size); // Temporary vector to store current level values

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Determine index based on traversal direction
                int index = flag ? i : size - 1 - i;
                row[index] = node->val;

                // Add child nodes for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Flip direction for next level
            flag = !flag;

            // Store current level result
            result.push_back(row);
        }

        return result;
    }
};
