class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int ,int>> st;
        unordered_map<int,list<pair<int,int>>> adj;

        for(auto t:times){
            int u=t[0];
            int v=t[1];
            int time=t[2];

            adj[u].push_back({v,time});
        }

        vector<int> key(n+1,INT_MAX);
        key[k]=0;

        st.insert({0,k});

        while(!st.empty()){
            auto top=*(st.begin());
            st.erase(st.begin());
            int time=top.first;
            int node=top.second;

            for(auto i:adj[node]){
                int t=i.second;
                int value=i.first;

                if(time+t<key[value]){
                    auto record=st.find({key[value],value});
                    if(record!=st.end()){
                        
                        st.erase(record);
                    }

                    key[value]=t+time;
                    st.insert({key[value],value});

                }


            }

        }



        for(int i=1;i<key.size();i++){
            if(key[i]==INT_MAX){
                return -1;
            }
        }

                key[0]=-1;



        int maxi=INT_MIN;
        for(int i=0;i<key.size();i++){
            maxi=max(key[i],maxi);
        }


        return maxi;


    }
};
