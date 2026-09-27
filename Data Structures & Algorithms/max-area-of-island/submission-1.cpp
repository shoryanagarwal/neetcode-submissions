class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> v(n,vector<bool> (m,false));
        int maxArea=0;

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 int area=0;

                if(!v[i][j] && grid[i][j]==1){
                   
                    q.push({i,j});
                    v[i][j]=true;
                    area=1;


                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                       
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];

                            if(nx<0 || ny<0 || nx>=n || ny>=m|| grid[nx][ny]==0 ||v[nx][ny]==true){
                                continue;
                            }

                            q.push({nx,ny});
                            v[nx][ny]=true;
                             area++;
                            


                        }

                    }
                     
                }
                maxArea=max(maxArea,area);

               


            }
        }


        return maxArea;


    }
};
