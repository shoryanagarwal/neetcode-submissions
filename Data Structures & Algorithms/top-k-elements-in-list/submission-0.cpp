class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> store(nums.size()+1);

        for(auto i:freq){
            store[i.second].push_back(i.first);
        }
        vector<int> ans;

        for(int i=store.size()-1;i>=0 && k>0 ;i--){

            vector<int> s=store[i];
            if(k>0){
                k-=s.size();

                for(int j=0;j<s.size();j++){
                    ans.push_back(s[j]);
                    
                }
                
            }
                
            

            

        }

        return ans;





    }
};
