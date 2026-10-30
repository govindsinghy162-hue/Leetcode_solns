
class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, int left, int right) {

        if (left > right)
            return NULL;

        // Preorder ka first element root hai
        int rootValue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Inorder mein root ki position
        int mid = mp[rootValue];

        // Left subtree
        root->left = solve(preorder, left, mid - 1);

        // Right subtree
        root->right = solve(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        preIndex = 0;

        // Inorder ke elements ki position store karo
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, 0, inorder.size() - 1);
    }
};
