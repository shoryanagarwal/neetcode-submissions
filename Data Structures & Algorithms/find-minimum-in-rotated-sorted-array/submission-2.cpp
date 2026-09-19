class Solution {
public:
    int findMin(vector<int> &nums) {
        //first check whether the array is rotated or not
        int n=nums.size()-1;
        int ans=INT_MAX;
         if(nums.size()==1){
                return nums[0];
            }
        if(nums[0]>nums[n]){
            
            int i=0;
            int j=n;

           


            while(i<=j){

                int mid=(i+j)/2;
                if(nums[mid]>nums[j]){
                    i=mid+1;
                }
                else {
                    ans=min(ans,nums[mid]);
                    j=mid-1;
                }


            }




        }
        else {
            
           return nums[0];




        }

        return ans;
    }
};
