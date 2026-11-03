
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: Both nodes are NULL
        if(p == NULL && q == NULL) {
            return true;
        }

        // Case 2: One node is NULL
        if(p == NULL || q == NULL) {
            return false;
        }

        // Case 3: Values are different
        if(p->val != q->val) {
            return false;
        }

        // Check left and right subtree
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
