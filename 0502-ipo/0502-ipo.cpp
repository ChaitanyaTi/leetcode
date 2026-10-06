class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>pro;
        for(int i =0; i<profits.size(); i++){
            pro.push_back({capital[i],profits[i]});
        }
        sort(pro.begin(),pro.end());
        priority_queue<int>pq;
        int idx = 0;
        while(k--){
            while(idx < pro.size()){
                if(w < pro[idx].first){
                    break;
                }
                else{
                    pq.push(pro[idx].second);
                    idx++;
                }
            }
            if(pq.empty()){
                return w;
            }
            w = w + pq.top();
            pq.pop();
        }
        return w;
    }
};