class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());

        if(!st.count(endWord)){
            return 0;
        }


        q.push({beginWord,1});


        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();


            if(word==endWord){
                return level;
            }

            for(int i=0;i<beginWord.size();i++){
                for(char j='a';j<='z';j++){
                    string test=word;
                    test[i]=j;

                    if(st.count(test)){
                        q.push({test,level+1});
                        st.erase(test);
                    }
                }
            }

        }

        return 0;
        


    }
};
