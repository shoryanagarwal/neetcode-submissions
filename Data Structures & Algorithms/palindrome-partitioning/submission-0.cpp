class Solution {





private:
    bool palindrome(string value){
        string v=value;

        reverse(v.begin(),v.end());

        if(value==v){
            return true;
        }
        else{
            return false;
        }




    }


    void solve(vector<string>& store,vector<vector<string>> &ans,string s){

        if(s==""){
            ans.push_back(store);
            return ;
        }


        for(int i=0;i<s.length();i++){

            string value=s.substr(0,i+1);

            if(palindrome(value)){
                store.push_back(value);
                solve(store,ans,s.substr(i+1));
                store.pop_back();

            }




        }





    }




public:
    vector<vector<string>> partition(string s) {
        
        vector<string> store;
        vector<vector<string>> ans;

        solve(store,ans,s);


        return ans;


    }
};
