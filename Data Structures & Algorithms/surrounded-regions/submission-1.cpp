class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(),vector<bool> (board[0].size(),false));

        queue<pair<int,int>> q;

        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=true;

            }

            if(board[i][board[0].size()-1]=='O'){
                q.push({i,board[0].size()-1});
                visited[i][board[0].size()-1]=true;
            }
        }

        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                visited[0][j]=true;
            }
            if(board[board.size()-1][j]=='O'){
                q.push({board.size()-1,j});
                visited[board.size()-1][j]=true;
            }
        }


        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<=3;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];


                if(nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size() && board[nx][ny]=='O' && !visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }



        }



        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && !visited[i][j]){
                board[i][j]='X';
                }
            }
        }


        
    }
};
