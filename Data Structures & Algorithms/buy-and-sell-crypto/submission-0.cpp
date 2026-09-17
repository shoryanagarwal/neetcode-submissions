class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int miniPrice=INT_MAX;
        int profit=0;

        for(int i=0;i<prices.size();i++){
            miniPrice=min(miniPrice,prices[i]);
            profit=max(profit,prices[i]-miniPrice);
        }

        return profit;
        

        

        
    }
};
