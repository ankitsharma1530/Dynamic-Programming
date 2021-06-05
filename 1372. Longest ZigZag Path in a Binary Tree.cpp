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
    // TC -> O(n) where n = number of nodes
     // space -> O(h) height of the tree
    

    int res = 0;
    void solve(TreeNode* root, string from_where_you_came, int length){
        if(root==NULL){
            return;
        }
        res = max(res,length);
        
        // this is case when we came from the left call
        if(from_where_you_came=="left"){
            // now we had 2 choices
            // 1. we can contiue to find the maximum length for zigzag
            // curr_node is a sub component of maximum zigzag path
            solve(root->right,"right",length+1);
            
            // 2. when we think that maximum zigzag length will be from this currnode
            // curr_node is the parent node for maximum zigag path
            solve(root->left,"left",1);
        }
        else{
            solve(root->left,"left",length+1);
            solve(root->right,"right",1);
            // instead of calling with 0 as we had did in main function
            // we call it with 1, because lets suppose if our right node exists
            // then the total distance of the zigzag path will be 1
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root,"left",0);
        // here we call with zero because there is no parent for the root node
        return res;
    }
};
