class Solution {
private:

    bool row(vector<vector<char>> &board){


        for(int i=0;i<9;i++){

            unordered_set<int> s;

            for(int j=0;j<9;j++){

                int value=board[i][j];
                if(value=='.'){
                    continue;
                }


                if(s.count(value)){
                    return false;
                }
                s.insert(value);

            }






        }

        return true;


    }


    bool col(vector<vector<char>> &board){


        for(int i=0;i<9;i++){

            unordered_set<int> s;

            for(int j=0;j<9;j++){

                int value=board[j][i];
                if(value=='.'){
                    continue;
                }


                if(s.count(value)){
                    return false;
                }
                s.insert(value);

            }






        }

        return true;


    }



    bool block(vector<vector<char>> &board){
        for(int startrow=0;startrow<9;startrow+=3){
            for(int startcol=0;startcol<9;startcol+=3){
        
         unordered_set<int> s;
        for(int i=startrow;i<startrow+3;i++){

           

            for(int j=startcol;j<startcol+3;j++){

                int value=board[i][j];
                if(value=='.'){
                    continue;
                }


                if(s.count(value)){
                    return false;
                }
                s.insert(value);

            }






        }
            }
        }
        return true;


    }




public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 3 directions--> row,column,block

        if(row(board) && col(board) && block(board)){
            return true;
        }
        else{
            return false;
        }




    }
};
