class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> v(n,vector<bool> (m,false) );

        queue<pair<int,int>> q;
        int fresh=0;

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }


            }
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!v[i][j] && grid[i][j]==2){
                    q.push({i,j});
                    v[i][j]=true;
                }


            }
        }

        int time=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty() && fresh>0){

            int size=q.size();

            for(int i=0;i<size;i++){

            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0 || ny<0 || nx>=n ||ny>=m || v[nx][ny]==true || grid[nx][ny]==0 ){
                    continue;
                }

                if(grid[nx][ny]==1 && v[nx][ny]==false){

                q.push({nx,ny});
                v[nx][ny]=true;
                fresh--;
                
                }


               


            }

            




        }

        time++;
        }
        

        if(fresh!=0){
            return -1;
        }
        return time;


    }
};
