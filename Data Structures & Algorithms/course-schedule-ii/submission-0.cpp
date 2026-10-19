class Solution {

private:


    

    bool dfs(int src,unordered_map<int,list<int>>& adj,vector<bool> &v,vector<bool> &path,stack<int> &st){

        v[src]=true;
        path[src]=true;

        for(auto i:adj[src]){
            if(!v[i]){
                if(dfs(i,adj,v,path,st)){
                    return true;
                }

            }
            else if(path[i]){
                return true;
            }
        }

        path[src]=false;
        st.push(src);



        return false;


    }



public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> ans;
        unordered_map<int,list<int>> adj;
        vector<bool> visited(numCourses,false);
        vector<bool> path(numCourses,false);
        stack<int> st;

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path,st)){
                    return ans;
                }
            }
            
        }



        while(!st.empty()){
            int top=st.top();
            st.pop();

            ans.push_back(top);
        }

        

        return ans;



        
    }
};
