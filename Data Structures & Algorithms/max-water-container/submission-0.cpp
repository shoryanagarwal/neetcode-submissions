class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int ans=0;

        while(i<j){
            //checking for the 1st pair 
            int maxWater=min(heights[i],heights[j]);
            int width=j-i;

            int area=maxWater*width;
            ans=max(ans,area);

            if(maxWater==heights[i]){
                i++;
            }
            else{
                j--;

            }







        }

        return ans;

        
    }
};
