#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MAX);
    }

private:
    TreeNode* buildBST(vector<int>& preorder, int& index, int bound) {
        // Base case: if all elements are processed or the current element exceeds the bound
        if (index >= preorder.size() || preorder[index] > bound) {
            return nullptr;
        }

        // Create the root node with the current preorder value
        TreeNode* root = new TreeNode(preorder[index++]);

        // Elements smaller than the current root's value go to the left subtree
        root->left = buildBST(preorder, index, root->val);

        // Elements smaller than the inherited parent bound go to the right subtree
        root->right = buildBST(preorder, index, bound);

        return root;
    }
};
