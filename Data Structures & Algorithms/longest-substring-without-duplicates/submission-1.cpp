class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window 
        unordered_set<char> store;

        int left=0;
        int right=0;

        int len=0;

        while(right<s.length()){
            while(store.find(s[right])!=store.end()){
                store.erase(s[left]);
                left++;
            }

            store.insert(s[right]);
            len=max(len,right-left+1);
            right++;

        }


       return len;
    }
};
