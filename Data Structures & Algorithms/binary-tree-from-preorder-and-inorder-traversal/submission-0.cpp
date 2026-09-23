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

    int findNode(vector<int> &inorder,int start,int end,int value){

        for(int i=start;i<=end;i++){
            if(value==inorder[i]){
                return i;
            }
        }

        return -1;


    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int end,int start){

        if(start>end){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[index++]);

        int found=findNode(inorder,start,end,root->val);


        root->left=solve(preorder,inorder,index,found-1,start);
        root->right=solve(preorder,inorder,index,end,found+1);

        return root;




    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return solve(preorder,inorder,index,inorder.size()-1,0);




        


        
    }
};
