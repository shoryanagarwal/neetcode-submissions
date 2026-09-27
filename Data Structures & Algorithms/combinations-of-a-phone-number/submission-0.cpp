class Solution {

private:

    void solve(string digits,string mp[],vector<string> &ans,string str,int index){


        if(index>=digits.length()){
            ans.push_back(str);
            return;
        }


        int value=digits[index]-'0';
        string st=mp[value];


        for(int i=0;i<st.length();i++){
            str.push_back(st[i]);
            solve(digits,mp,ans,str,index+1);
            str.pop_back();



        }








    }



public:
    vector<string> letterCombinations(string digits) {
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string> ans;
        string str;

        if(digits.length()==0){
            return ans;
        }

        solve(digits,mp,ans,str,0);


        return ans;




        



    }
};
