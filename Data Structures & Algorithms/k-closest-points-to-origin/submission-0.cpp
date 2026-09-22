class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){

            int dist=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.push({dist,{points[i][0],points[i][1]}});

            if(pq.size()>k){
                pq.pop();
            }

        }


        vector<vector<int>> ans;;

        while(!pq.empty()){
            pair<int,pair<int,int>> value=pq.top();
            ans.push_back({value.second.first,value.second.second});
            pq.pop();
        }


        return ans;






    }
};
