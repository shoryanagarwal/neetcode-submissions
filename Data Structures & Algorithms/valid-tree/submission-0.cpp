class Solution {

    private:
    bool dfs(int node,unordered_map<int,list<int>> &adj,vector<bool> &v,vector<int> &parent){


        v[node]=true;
        
        for(auto i:adj[node]){
            if(!v[i]){
                parent[i]=node;
                if(dfs(i,adj,v,parent)){
                    return true;
                }
            }
            else if(parent[node]!=i){
                return true;
            }

        }


        return false;




    }


public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        vector<bool> v(n,false);
        vector<int> parent(n,-1);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        if(dfs(0,adj,v,parent)){
            return false;
        }

        for(int i=0;i<n;i++){
            if(!v[i]){
                return false;
            }
        }

        

        return true;





    }
};
