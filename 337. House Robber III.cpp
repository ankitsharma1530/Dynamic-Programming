class Solution {
public:
    pair<int,int> solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        pair<int,int>res;
        res.first = root->val+left.second+right.second;
        res.second = max(left.first,left.second)+max(right.first,right.second);
        return res;
    }
    int rob(TreeNode* root) {
        pair<int,int>temp=solve(root);
        return max(temp.first,temp.second);
    }
};
