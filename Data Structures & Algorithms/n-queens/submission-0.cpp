class Solution {

    private:

    void add(vector<vector<string>> &ans,int n,vector<vector<char>> &board){

        vector<string> temp;

        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<n;j++){
                str.push_back(board[i][j]);


            }

            temp.push_back(str);
        }


        ans.push_back(temp);



    }

    bool isSafe(int row,int col,vector<vector<char>> &board,int n){

        int x=row;
        int y=col;

        while(y>=0){

            if(board[x][y]=='Q'){
                return false;
            
            }

            y--;

        }


        int c=row;
        int d=col;

        while(c<n && d>=0){
            if(board[c][d]=='Q'){
                return false;
            }

            c++;
            d--;
        }

        int a=row;
        int b=col;

        while(a>=0 && b>=0){
            if(board[a][b]=='Q'){
                return false;
            }

            a--;
            b--;
        }


        return true;



    }




    void solve(int n,vector<vector<char>> &board,vector<vector<string>> &ans,int col){


        if(col==n){
            add(ans,n,board);
            return;
        }

        for(int row=0;row<n;row++){

            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(n,board,ans,col+1);
                board[row][col]='.';
            }



        }



    }


public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char> (n,'.'));
        vector<vector<string>> ans;

        solve(n,board,ans,0);
        return ans;

    }
};
