class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return buildTree(preorder, pos, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int& pos, vector<int>& inorder, int left, int right) {
        if (pos >= preorder.size()) return 0;
        int i = left;
        for (i = left; i <= right; ++i) {
            if (inorder[i] == preorder[pos]) break;
        }
        TreeNode* node = new TreeNode(preorder[pos]);
        if (left <= i-1) node->left = buildTree(preorder, ++pos, inorder, left, i-1);  // 左子树
        if (i+1 <= right) node->right = buildTree(preorder, ++pos, inorder, i + 1, right);  // 右子树
        return node;
    }
};