class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int lTree = minDepth(root->left), rTree = minDepth(root->right);
        return 1 + (min(lTree, rTree), min(lTree, rTree), max(lTree, rTree));
    }
};

