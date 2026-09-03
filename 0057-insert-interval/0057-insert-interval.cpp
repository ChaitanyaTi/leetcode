class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& finans) {
        vector<vector<int>> res;
        sort(finans.begin(),finans.end());
        int start = finans[0][0];
        int end = finans[0][1];
        for(int i =1; i<finans.size(); i++){
            int s = finans[i] [0];
            int e = finans[i] [1];
            if(end >= s){
                end = max(end,e);
                continue;
            }
            res.push_back({start,end});
            start = s;
            end = e;
        }
        res.push_back({start,end});
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> finans;
        bool tag = false;
        int start;
        int end;
        for(int i = 0; i<intervals.size(); i++){
            start = intervals[i][0];
            end = intervals[i][1];
            int checks = newInterval[0];
            int checke = newInterval[1];
            if(tag == false && start >= checks ){
                finans.push_back({checks,checke});
                tag = true;
            }
            finans.push_back({start,end});
        }
        if (!tag) {
            finans.push_back(newInterval);
        }
        return merge(finans);
    }
};