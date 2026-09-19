class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long total=0;
        for(int i=0;i<piles.size();i++){
            total+=piles[i];
        }
        
        long long k=1;
        long long j=total;
        long long ans=total;
            
        while(k<=j){
            long long mid=(k+j)/2;

            long long count=0;

            for(int i=0;i<piles.size();i++){
                if(mid>(long long)piles[i]){
                    count++;
                }
                else{
                   if((long long)piles[i]%mid==0){
                    count+=(long long)piles[i]/mid;
                   }
                   else{
                    count+=(long long)piles[i]/mid + 1;
                   }
                }
            
            }
           

            if(count<=h){
                ans=min(ans,mid);
                j=mid-1;
            }
            else{
                k=mid+1;
            }


            
            
            
            
        }


        return (int)ans;
    }
};
