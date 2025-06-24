class Solution {
public:
    // Helper function to compute max path sum from current node
    int maxSum(TreeNode* node, int &maxi){
        if(node == NULL) return 0;

        // Compute max path sum on left and right subtrees; ignore negatives
        int lh = max(0, maxSum(node->left, maxi));
        int rh = max(0, maxSum(node->right, maxi));

        // Update global maximum path sum considering current node as root
        maxi = max(maxi, node->val + lh + rh);

        // Return max path sum for one side to be used in parent computation
        return (node->val + max(lh, rh));
    }

    // Main function to initiate the process
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxSum(root, maxi);
        return maxi;
    }
};