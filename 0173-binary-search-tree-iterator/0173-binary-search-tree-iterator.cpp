#include <stack>

class BSTIterator {
private:
    std::stack<TreeNode*> myStack;

    // Helper function to push all left children of a node
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAllLeft(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};
