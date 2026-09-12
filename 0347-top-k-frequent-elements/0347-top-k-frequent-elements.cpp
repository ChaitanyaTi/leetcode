class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int,int>f;
        for(int i=0; i<nums.size(); i++){
            f[nums[i]]++;
        }
        for(auto it : f){
            int freq = it.second;
            int digit = it.first;
            pair<int,int>curr = {freq,digit};
            if(pq.size() < k){
                pq.push(curr);
            }
            else if(curr.first<pq.top().first){
                continue;
            }
            else{
                pq.pop();
                pq.push(curr);
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};