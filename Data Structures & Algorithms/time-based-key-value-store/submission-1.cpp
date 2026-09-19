class TimeMap {
public:
     unordered_map<string,vector<pair<int,string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans="";
            vector<pair<int,string>> &v=store[key];   

            int n=v.size();

            int k=0;
            int j=n-1;

            while(k<=j){

                int mid=(k+j)/2;
                if(v[mid].first<=timestamp){
                    ans=v[mid].second;
                    k=mid+1;
                }

                else{
                    j=mid-1;
                }



            }



        


        return ans;


    }
};
