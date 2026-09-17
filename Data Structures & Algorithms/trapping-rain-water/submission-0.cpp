class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        prefix[0]=height[0];
        suffix[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size();i++){
            prefix[i]=max(height[i],prefix[i-1]);
        }

        for(int i=height.size()-2;i>=0;i--){
            suffix[i]=max(height[i],suffix[i+1]);
        }

        int ans=0;

        for(int i=0;i<height.size();i++){
            int water=min(prefix[i],suffix[i])-height[i];

            ans+=water;
        }


        return ans;



    }
};
