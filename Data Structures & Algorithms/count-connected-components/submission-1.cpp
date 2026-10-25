class Solution {

private:
    void dfs(int n,unordered_map<int,list<int>> &adj,int node,vector<bool>& v){
        v[node]=true;

        for(auto i:adj[node]){
            if(!v[i]){
                dfs(n,adj,i,v);
            }
        }
    }


public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int count=0;


        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(n,adj,i,visited);
            }
        }



        return count;




    }
};
