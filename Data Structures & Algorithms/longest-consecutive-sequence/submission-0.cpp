class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(int i=0;i<nums.size();i++){

            s.insert(nums[i]);


        }

        int ans=0;


        for(auto x:s){

            if(s.find(x-1)==s.end()){
                int curr=x;
                int len=1;


                while(s.find(curr+1)!=s.end()){
                    len++;
                    curr++;
                }



                ans=max(ans,len);



            }





        }


        return ans;

    }
};
