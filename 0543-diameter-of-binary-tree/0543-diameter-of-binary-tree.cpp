class Solution {
public:
    int diameter = 0;

    int height(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Diameter passing through this node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of the subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};