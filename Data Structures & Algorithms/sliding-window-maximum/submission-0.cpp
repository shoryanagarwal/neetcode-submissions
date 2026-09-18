class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
       
        vector<int> ans;

        for(int i=0;i<k;i++){
            while(!q.empty() &&  nums[q.back()]<=nums[i]){
                q.pop_back();
            }


            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);

        for(int right=k;right<nums.size();right++){
            while(!q.empty() && q.front()<=right-k){
                q.pop_front();
            }

            while(!q.empty() && nums[q.back()]<=nums[right]){
                q.pop_back();
            }
            q.push_back(right);
            ans.push_back(nums[q.front()]);
            
        }


        return ans;

    }
};
