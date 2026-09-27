class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==0){
                    q.push({i,j});
                }


            }
        }


        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        

                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;

                    q.pop();

                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];


                        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]==-1){
                            continue;
                        }

                        if(grid[nx][ny]>grid[x][y]+1){
                            grid[nx][ny]=grid[x][y]+1;
                            q.push({nx,ny});
                        }
                        
                        




                    }

                }

            




    }
};
