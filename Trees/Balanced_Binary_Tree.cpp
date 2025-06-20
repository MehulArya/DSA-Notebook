class Solution {
public:
    int checkdepth(TreeNode* root) {
        if (root == NULL) return 0; // Base case: empty tree has height 0

        int lh = checkdepth(root->left);  // Height of left subtree
        if (lh == -1) return -1;          // Left subtree is unbalanced

        int rh = checkdepth(root->right); // Height of right subtree
        if (rh == -1) return -1;          // Right subtree is unbalanced

        if (abs(lh - rh) > 1) return -1;  // Current node is unbalanced

        int h = 1 + max(lh, rh);          // Height of current node
        return h;
    }

    // Returns true if the tree is balanced
    bool isBalanced(TreeNode* root) {
        return checkdepth(root) != -1;
    }
};
