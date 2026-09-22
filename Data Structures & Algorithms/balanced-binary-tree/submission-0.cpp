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
   int solve(TreeNode* root,vector<int> &store){
        if(root==NULL){
            return 0;
        }

       int left=solve(root->left,store);
        int right=solve(root->right,store);

       

        if(abs(left-right)>1){
            store[0]=1;
        }
        


        return 1+max(left,right);



    }



public:
    bool isBalanced(TreeNode* root) {
        vector<int> store(1,0);

        solve(root,store);

        return store[0]==0;


        
    }
};
