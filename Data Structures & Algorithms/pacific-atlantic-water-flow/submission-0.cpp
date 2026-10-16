class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> ans;
        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;
        vector<vector<bool>> p(heights.size(),vector<bool> (heights[0].size(),false));
        vector<vector<bool>> a(heights.size(),vector<bool> (heights[0].size(),false)); 

        

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        for(int i=0;i<heights.size();i++){
            pq.push({i,0});
            p[i][0]=true;
            aq.push({i,heights[0].size()-1});
            a[i][heights[0].size()-1]=true;
        }
        for(int i=0;i<heights[0].size();i++){
            aq.push({heights.size()-1,i});
             
            pq.push({0,i});
            a[heights.size()-1][i]=true;
            p[0][i]=true;
        }





        //bfs for pacific;
        while(!pq.empty()){

            int x=pq.front().first;
            int y=pq.front().second;

            pq.pop();

            for(int i=0;i<=3;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx >=0 && nx <heights.size() && ny>=0 && ny<heights[0].size() && !p[nx][ny] &&               heights[nx][ny] >= heights[x][y]){
                    pq.push({nx,ny});
                    p[nx][ny]=true;
                }


            }




        }



         while(!aq.empty()){

            int x=aq.front().first;
            int y=aq.front().second;

            aq.pop();

            for(int i=0;i<=3;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx >=0 && nx <heights.size() && ny>=0 && ny<heights[0].size() && !a[nx][ny] &&               heights[nx][ny] >= heights[x][y]){
                    aq.push({nx,ny});
                    a[nx][ny]=true;
                }


            }




        }



        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(p[i][j] && a[i][j]){
                    ans.push_back({i,j});
                }
            }
        }


        return ans;
        
    }
};
