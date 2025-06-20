bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // If either node is null, return true only if both are null
    if (p == NULL || q == NULL) {
        return p == q;
    }

    // Check current node values, then recursively check left and right subtrees
    return (p->val == q->val) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
