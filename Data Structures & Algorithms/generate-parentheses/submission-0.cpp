class Solution {
private:
    void solve(string temp,vector<string> &ans,int n,int open,int close){

        if(open==n && close==n && open+close==2*n){

            ans.push_back(temp);
            return;

        }



        if(open<n){
            solve(temp+'(',ans,n,open+1,close);
        }

        if(close<open){
            solve(temp+')',ans,n,open,close+1);
        }

        temp.pop_back();





    }



public:
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> ans;

        solve(temp,ans,n,0,0);

        return ans;


    }
};
