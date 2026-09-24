class Solution {
private:

    void solve(vector<vector<int>> &ans,vector<int> &temp,vector<bool> &vis,vector<int>& nums){

        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }


        for(int i=0;i<nums.size();i++){
            if(vis[i]==false){
                temp.push_back(nums[i]);
                vis[i]=true;
                solve(ans,temp,vis,nums);
                temp.pop_back();
                vis[i]=false;



            }
        }



    }


public:
    vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> temp;

            vector<bool> vis(nums.size(),false);

            solve(ans,temp,vis,nums);
            return ans;
    }
};
