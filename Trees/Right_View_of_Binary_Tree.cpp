class Solution {
public:
    // Helper function to perform a modified DFS traversal
    // It visits the right subtree first to capture the rightmost node at each level
    void helper(TreeNode* node, int level, vector<int> &res) {
        if (node == NULL) return; // Base case: if node is null, do nothing

        // If this is the first node we're visiting at this level,
        // add it to the result vector as it's the rightmost one seen so far
        if (res.size() == level)
            res.push_back(node->val);

        // Recurse to the right subtree first so rightmost nodes are prioritized
        helper(node->right, level + 1, res);

        // Then recurse to the left subtree
        helper(node->left, level + 1, res);
    }

    // Main function to return the list of rightmost nodes at each level
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; // Stores the right side view of the binary tree
        helper(root, 0, res); // Start DFS traversal from level 0
        return res;
    }
};
