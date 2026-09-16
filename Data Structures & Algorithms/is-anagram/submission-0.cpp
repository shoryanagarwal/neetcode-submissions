class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> freqs;
        unordered_map<int,int> freqt;
        
        if(s.length()!=t.length()){
            return false;

        }


        for(int i=0;i<s.length();i++){
            freqs[s[i]]++;
            freqt[t[i]]++;
        }

        for(int i=0;i<s.length();i++){
            if(freqs[s[i]]!=freqt[s[i]]){
                return false;
            }
        }


        return true;

        



    }
};
