class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            

            while(j<k){
                
                if(nums[j]+nums[k]==(-nums[i])){
                    ans.push_back({nums[i],nums[j],nums[k]});

                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(k>j && nums[k]==nums[k-1]){
                        k--;
                    }

                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>(-nums[i])){
                    k--;
                }
                else{
                    j++;
                }



            }

        }

        return ans;
    }
};
