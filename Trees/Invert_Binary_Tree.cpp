class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the current node is null, return null
        if(root == NULL) return root;

        // Swap the left and right children of the current node
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        // Return the root after inverting its subtree
        return root;
    }
};
