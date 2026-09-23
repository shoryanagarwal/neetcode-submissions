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

    int maxSum=INT_MIN;


    int solve(TreeNode* root){

        if(!root){
            return 0;
        }

        int left=solve(root->left);
        int right=solve(root->right);

        // 1 st option
        int dono_hi_ache=left + right + root->val;
        

        //2 nd option
        int dono_mai_se_ek_acha=max(left,right) + root->val;

        //3rd option
        int dono_bekar=root->val;

        maxSum=max({maxSum,dono_hi_ache,dono_mai_se_ek_acha,dono_bekar});

        return max(dono_mai_se_ek_acha,dono_bekar);


    }


    int maxPathSum(TreeNode* root) {
            //3 cases
            //1. dono hi ache mil jaye left and right
            //2. dono mai se ek acha mile
            //3. sirf root acha mile

        solve(root);
        return maxSum; 
        


    }
};
