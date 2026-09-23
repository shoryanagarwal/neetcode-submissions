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
        
        if(!root || !p || !q){
            return NULL;
        }


        if(root->val == p->val || root->val==q->val){
            return root;
        }

        TreeNode* leftSide=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSide=lowestCommonAncestor(root->right,p,q);

        if(leftSide!=NULL && rightSide!=NULL){
            return root;
        }

        if(leftSide!=NULL){
            return leftSide;
        }


        return rightSide;


        


    }
};
