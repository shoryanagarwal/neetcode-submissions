class Solution {

private:
    void solve(vector<int>& nums, int target,vector<int>& temp,int index, vector<vector<int>> &ans ){

        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(target<0 || index>=nums.size()){
            return ;
        }

        temp.push_back(nums[index]);
        solve(nums,target-nums[index],temp,index,ans);
        temp.pop_back();
        solve(nums,target,temp,index+1,ans);


    }


public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        vector<int> temp;

        solve(nums,target,temp,0,ans);

        return ans;

    }
};
