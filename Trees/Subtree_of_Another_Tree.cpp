class Solution {
public:
    // Function to serialize a binary tree using preorder traversal
    // It includes null markers ("#") and value delimiters to preserve structure
    string preorderTraversal(TreeNode* node) {
        if (node == NULL) return "#"; // Base case: null node is marked with '#'

        string sb = "";

        // Add current node value wrapped in parentheses and separated by commas
        sb += "(" + to_string(node->val) + "," + ")";

        // Recursively serialize the left subtree
        sb += preorderTraversal(node->left) + ",";

        // Recursively serialize the right subtree
        sb += preorderTraversal(node->right);

        return sb;
    }

    // Main function to determine if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Serialize both the full tree and the subtree
        string fullTree = preorderTraversal(root);
        string subTree = preorderTraversal(subRoot);

        // Check if the serialized subtree appears in the serialized full tree
        // If found, return true; otherwise, return false
        return fullTree.find(subTree) != string::npos;
    }
};
