class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()){
            return "";
        }   

        unordered_map<char,int> freq1;
        for(int i=0;i<t.length();i++){
            freq1[t[i]]++;
        }
        int left=0;
        unordered_map<char,int> freq2;
        int have=0;
        int len=INT_MAX;
        int start=-1;

        for(int right=0;right<s.length();right++){
            freq2[s[right]]++;

            if(freq2[s[right]]<=freq1[s[right]]){
                have++;
            }

            while(have==t.length()){

                if(right-left+1<len){
                    len=right-left+1;
                    start=left;
                }
                freq2[s[left]]--;


                if(freq2[s[left]]<freq1[s[left]]){
                    have--;
                    
                    
                }
                left++;

                



            }




        }

        if(start==-1){
            return "";
        }

        return s.substr(start,len);

        
    }
};
