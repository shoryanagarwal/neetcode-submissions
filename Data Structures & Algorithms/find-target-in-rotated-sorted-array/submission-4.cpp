class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();


        if(nums.size()==1){
            if(target==nums[0]){
                return 0;
            }
            else{
                return -1;
            }
        }

        if(nums[0]>nums[n-1]){
            // rotated array hai
            int i=0;
            int j=n-1;

            while(i<=j){

                int mid=(i+j)/2;

                if(nums[mid]==target){
                    return mid;
                }

                if(nums[mid]>=nums[i]){
                    if(target<nums[mid] && target >=nums[i] ){
                        j=mid-1;
                    }
                    else{
                        i=mid+1;
                    }
                }
                else{

                    if(nums[mid] < target && target <= nums[j]){
                        i=mid+1;
                    }
                    else{
                        j=mid-1;
                    }

                }






            }




        }    
        else{
            //rotated nhi hai

            int i=0;
            int j=n-1;

            while(i<=j){
                int mid=(i+j)/2;


                if(target==nums[mid]){
                    return mid;
                }
                if(target>nums[mid]){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
        }


        return -1;


    }
};
