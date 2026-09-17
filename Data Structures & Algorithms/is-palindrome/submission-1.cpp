class Solution {

void generate(string s,string &ans){

    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            char value=s[i]+('a'-'A');
            s[i]=value;
        }    
    }

    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
    }







}



bool palindrome(string ans){

    int i=0;
    int j=ans.length()-1;


    while(i<j){
        if(ans[i]!=ans[j]){
            return false;
        }
        i++;
        j--;
    }


    return true;




}


public:
    bool isPalindrome(string s) {
        

        string ans="";

        generate(s,ans);

        
        bool check=palindrome(ans);
        return check;




    }
};
