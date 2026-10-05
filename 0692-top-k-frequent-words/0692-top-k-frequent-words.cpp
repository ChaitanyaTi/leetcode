class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            else{
                return b.second > a.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>f;
        for(int i =0; i<words.size(); i++){
            f[words[i]]++;
        }
        vector<string>res;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(auto it : f){
            string first = it.first;
            int second = it.second;
            pq.push({second,first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};