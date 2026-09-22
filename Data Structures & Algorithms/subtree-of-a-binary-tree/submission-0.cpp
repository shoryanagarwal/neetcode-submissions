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
    bool isSame(TreeNode* root,TreeNode* subRoot){

        if(!subRoot && !root){
            return true;
        }

        if(subRoot && root && subRoot->val==root->val){
            return    isSame(root->left,subRoot->left) && isSame(root->right,subRoot->right);
        }

        return false;


    }


public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }

        if(!subRoot){
            return true;
        }
        
        if(isSame(root,subRoot)){
            return true;
        }


        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);



    }
};
