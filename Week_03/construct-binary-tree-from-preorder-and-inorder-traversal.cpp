#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]] = i;
        }

        int prei = 0;

        return Helper(preorder,m,0,inorder.size(),prei);
    }

    TreeNode* Helper(vector<int>& preorder,unordered_map<int,int>& m,int left,int right,int& prei)
    {
        if(left==right)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prei]);

        auto it = m.find(preorder[prei]);
        int temp = it->second;

        prei++;

        root->left = Helper(preorder,m,left,temp,prei);
        root->right = Helper(preorder,m,temp+1,right,prei);

        return root;
    }
};