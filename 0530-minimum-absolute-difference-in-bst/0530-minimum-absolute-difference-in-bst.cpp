class Solution {
public:
    int ans = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if(root == nullptr)
            return;

        inorder(root->left);

        if(prev != nullptr)
            ans = min(ans, root->val - prev->val);

        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};