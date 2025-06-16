class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: if the tree is empty, its depth is 0
        if(root == NULL) return 0;

        // Recursively find the depth of the left subtree
        int lh = maxDepth(root->left);

        // Recursively find the depth of the right subtree
        int rh = maxDepth(root->right);

        // The depth of the tree is the maximum of the two subtrees' depths plus 1 (for the current node)
        return 1 + max(lh, rh);
    }
};
