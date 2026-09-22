class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> store(26,0);
        queue<pair<int,int>> q;


        for(int i=0;i<tasks.size();i++){
            store[tasks[i]-'A']++;
        }

        for(int i=0;i<store.size();i++){
            if(store[i]>0){
                pq.push(store[i]);
            }
        }
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;

            if(pq.empty()){
                time=q.front().second;
            }
            else{
                int count=pq.top()-1;
                pq.pop();
                if(count>0){
                q.push({count,time+n});
                }
            }

            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }


        }



        return time;


        
    }
};
