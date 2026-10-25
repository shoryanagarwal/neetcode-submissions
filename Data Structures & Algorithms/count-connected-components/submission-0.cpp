class Solution {
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
            if(visited[i]){
                continue;
            }

            queue<int> q;
            q.push(i);
            visited[i]=true;
            count++;

            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto val:adj[front]){
                    if(!visited[val]){
                        q.push(val);
                        visited[val]=true;
                    }
                }
                
            }
        }



        return count;
    }
};
