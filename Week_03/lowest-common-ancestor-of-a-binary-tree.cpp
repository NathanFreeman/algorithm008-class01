class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 递归终止条件
        if (NULL == root || root == p || root == q) {
            return root;
        }

        // 内在逻辑
        //先找左子树有没有p或者q
        TreeNode left = lowestCommonAncestor(root->left, p, q);
        //再找左子树有没有p或者q
        TreeNode right = lowestCommonAncestor(root->right, p, q);
        if(left == null && right == null) return null;
        if(left != null && right != null) return root;
        return left == null ? right : left;
    }
};

