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
private:
    bool solve(TreeNode* root,long long low,long long high){
        if(root==NULL){
            return true;
        }


        if(root->val <=low || root->val >=high){
            return false;
        }


        bool leftSide=solve(root->left,low,root->val);
        bool rightSide=solve(root->right,root->val,high);

        return leftSide && rightSide;




    }



public:
    bool isValidBST(TreeNode* root) {

        bool ans=solve(root,LLONG_MIN, LLONG_MAX);
        return ans;

        
    }
};
