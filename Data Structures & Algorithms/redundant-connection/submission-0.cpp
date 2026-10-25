class Solution {

private:

    bool dfs(int node,int target,unordered_map<int,list<int>> &adj,vector<bool>& v){

        if(node==target){
            return true;
        }

        v[node]=true;


        for(auto i:adj[node]){
            if(!v[i]){
                if(dfs(i,target,adj,v)){
                    return true;
                }
            }
        }
        return false;



    }


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;

        for(auto e:edges){
            int u=e[0];
            int v=e[1];

            vector<bool> vis(edges.size(),false);
            if(dfs(u,v,adj,vis)){
                return e;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);

        }



        return {};
    }
};
