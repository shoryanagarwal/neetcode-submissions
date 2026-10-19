class Solution {

private:
    bool dfs(int src,unordered_map<int,list<int>>& adj,vector<bool> &v,vector<bool> &path){

        v[src]=true;
        path[src]=true;


        for(auto i:adj[src]){
            if(!v[i]){
                if(dfs(i,adj,v,path)){
                    return true;
                }
            }
            else if(path[i]){
                return true;
            }
        }


        path[src]=false;
        return false;





    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        vector<bool> v(numCourses,false);
        vector<bool> path(numCourses,false);

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }



        for(int i=0;i<numCourses;i++){
            if(!v[i]){
                if(dfs(i,adj,v,path)){
                    return false;
                }
            }
        }


        return true;




    }
};
