class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq;
        unordered_map<char,int> freq2;

        for(int i=0;i<s1.length();i++){
            freq[s1[i]]++;
        }


        int left=0;
        for(int right=0;right<s2.length();right++){

            freq2[s2[right]]++;

            if(right-left+1>s1.length()){
                freq2[s2[left]]--;

                if(freq2[s2[left]]==0){
                    freq2.erase(s2[left]);
                }

                left++;


            }


            if(freq==freq2){
                return true;
            }




        }
        
        return false;
        
    }
};
