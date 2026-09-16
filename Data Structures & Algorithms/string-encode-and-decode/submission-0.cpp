class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";

        for(int i=0;i<strs.size();i++){

            string str=strs[i];

            int len=str.length();
            
            ans+=to_string(len);
            ans+="#";
            ans+=str;


        }



        return ans;



    }

    vector<string> decode(string s) {
        vector<string> ans;
         int i=0;

         while(i<s.length()){
        

        string conv="";
        string temp="";

       

        while(s[i]!='#'){
            conv+=s[i];
            i++;
        }

        int len=stoi(conv);
        i+=1;

        while(i<s.length() && len>0){

            temp+=s[i];
            i++;
            len--;


        }

        ans.push_back(temp);

         }



       
        return ans;




    }
};
