#include <vector>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> Q;
        TreeNode *T;
        vector<int> temp;
        vector<vector<int>> res;
        if(root== NULL) return res;
        Q.push_back(root);
        while(!Q.empty())
        {
            int size = Q.size();
            for (int i = 0; i < size;i++)
            {
                T = Q.front();
                temp.push_back(Q.front()->val);
                Q.pop_front();
                if(T->left)
                    Q.push_back(T->left);
                if(T->right)
                    Q.push_back(T->right);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};