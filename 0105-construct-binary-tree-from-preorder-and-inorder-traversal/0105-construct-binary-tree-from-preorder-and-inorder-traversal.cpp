/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int preindex=0;
    unordered_map<int,int>m;
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int si,int ei){
        if(si>ei)
            return NULL;
         TreeNode*root=new TreeNode(preorder[preindex++]);
        int inindex=m[root->val];
        root->left=solve(preorder,inorder,si,inindex-1);
        root->right=solve(preorder,inorder,inindex+1,ei);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++)
            m[inorder[i]]=i;
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};