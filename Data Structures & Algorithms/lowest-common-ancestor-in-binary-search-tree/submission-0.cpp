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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //check  karo ki p and q kaha ho skte hai p and q ka max lo aand check karo kya vop root se chote hai agar ha to left side mai jao nhi to min leke right side mai 

        if(!root || !p ||!q){
            return NULL;
        }


        if( max(p->val,q->val)<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if( min(p->val,q->val)>root->val){
           return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }




    }
};
