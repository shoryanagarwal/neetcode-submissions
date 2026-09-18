class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> ans;


        for(int i=0;i<position.size();i++){
            int dis=target-position[i];
            float t=(float)dis/speed[i];
           ans.push_back({position[i],t});
        }


        sort(ans.rbegin(),ans.rend());

        stack<float> st;
        

        for(int i=0;i<ans.size();i++){
            float time=ans[i].second;

            if(st.empty()){
                st.push(time);
            }

           else  if(st.top()<time){
                st.push(time);
            }
            


        }


        return st.size();
    }
};
