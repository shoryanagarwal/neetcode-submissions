class Solution {
private:

    bool solve(vector<vector<char>>& board, string word,int x,int y,int index){

        if(index>=word.size()){
            return true;
        }


        if(x<0 || y<0 || x>=board.size() || y>=board[0].size()){
            return false;
        }


        if(word[index]!=board[x][y]){
            return false;
        }

       char temp=board[x][y];
        board[x][y]='!';


       bool found=solve(board,word,x-1,y,index+1) || solve(board,word,x+1,y,index+1)
            || solve(board,word,x,y+1,index+1) || solve(board,word,x,y-1,index+1); 


        board[x][y]=temp;


        return found;
        






    }


public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }



        return false;






    }
};
