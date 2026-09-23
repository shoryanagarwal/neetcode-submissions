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


    int solve(TreeNode* root,int maxi){
        int count=0;
        if(root==NULL){
            return 0;
        }


        if(maxi<=root->val){
            count=1;
        }
        maxi=max(maxi,root->val);
        count+=solve(root->left,maxi)+ solve(root->right,maxi);
        


        return count;



    }

public:
    int goodNodes(TreeNode* root) { 
        
        int maxi=root->val;
        int ans=solve(root,maxi);


        return ans;




        
    }
};
