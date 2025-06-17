class Solution {
    // Helper function to calculate height of tree and update diameter
    int height(TreeNode* node, int &diameter){
        // Base case: height of null node is 0
        if(node == NULL) return 0;

        // Recursively calculate height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter if the path through this node is longer
        diameter = max(diameter, lh + rh);

        // Return height of current node as 1 + max of left/right subtree heights
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize diameter with the smallest possible integer
        int diameter = INT_MIN;

        // Call the helper function to compute height and update diameter
        height(root, diameter);

        // Return the final diameter value
        return diameter;
    }
};
