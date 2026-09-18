class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0;i<tokens.size();i++){

            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"  ){
                 st.push(stoi(tokens[i]));
                continue;
                

            }

            int val1=st.top();
            st.pop();
            int val2=st.top();
            st.pop();

            if(tokens[i]=="+"){
                int value=val1+val2;
                st.push(value);
            }
            else if(tokens[i]=="-"){
                int value=val2-val1;
                st.push(value);
            }
            else if(tokens[i]=="*"){
                int value=val2*val1;
                st.push(value);
            }
            else{
               
                int value=val2/val1;
                st.push(value);
            }
            




        }


        if(st.size()==1){
            return st.top();
        }
        
    }
};
