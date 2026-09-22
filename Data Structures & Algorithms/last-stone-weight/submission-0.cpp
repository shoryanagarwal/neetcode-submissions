class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {


        if(stones.size()==1){
            return stones[0];
        }

        priority_queue<int,vector<int>> pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();

            if(first==second){
                continue;
            }

            if(first>second){
                int value=first-second;
                pq.push(value);
            }
            else if(first<second){
                int value=second-first;
                pq.push(value);
            }



        }

        if(pq.size()==1){
            return pq.top();
        
        }

        return 0;



        
    }
};
