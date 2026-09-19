class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //phele row mai binaryu searching 
        int rowi=0;
        int rowj=matrix.size()-1;
        int col=matrix[0].size();
        int row=matrix.size();

        bool found=false;


        while(rowi<=rowj){
            int mid=(rowi+rowj)/2;


            if( matrix[mid][0]>target){
                rowj=mid-1;
            }
            else if(matrix[mid][col-1] < target){
                rowi=mid+1;
            }

           else {
                int i=0;
                int j=col-1;

                while(i<=j){
                    int m=(i+j)/2;
                    if(matrix[mid][m]==target){
                       return true;
                    }
                    if(matrix[mid][m]<target){
                        i=m+1;
                    }
                    else{
                        j=m-1;
                    }
                }

                return false;
            }

            


        }


        return false;
        
    }
};
