class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
           stack<int> st;
           int area=0;
           int nse=heights.size();
           int pse=-1;


           if(heights.size()==1){
            return heights[0];
           }

           for(int i=0;i<=heights.size();i++){

                int height;
                if(i==heights.size()){
                    height=0;
                }
                else{
                    height=heights[i];
                }

                while(!st.empty() && heights[st.top()]>height){
                    int top=st.top();
                    nse=i;
                    st.pop();
                    if(!st.empty()){
                       pse= st.top();
                    }
                    else{
                        pse=-1;
                    }

                    area=max(area,heights[top]*(nse-pse-1));


                }


                if(i<heights.size()){
                    st.push(i);
                }


           }

           return area;
    }
};
