class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store;

        for(int i=0;i<nums.size();i++){

            int difference=target-nums[i];

            if(store.find(difference)!=store.end()){
                return {store[difference],i};
            }
            else{
                store[nums[i]]=i;
            }



        }
        

    }
};
