class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size());
        ans[temperatures.size()-1]=0;
        st.push({temperatures[temperatures.size()-1],temperatures.size()-1});

        if(temperatures.size()==1){
            return {0};
        }

        for(int i=temperatures.size()-2;i>=0;i--){

           

            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=st.top().second-i;
            }

            st.push({temperatures[i],i});







        }
        

        
        return ans;
        




    }
};
