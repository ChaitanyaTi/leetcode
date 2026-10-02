class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1; i<intervals.size(); i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(end>=s){
                end = max(e,end);
                continue;
            }
            ans.push_back({start,end});
            start = s;
            end = e;
        }
        ans.push_back({start,end});
        return ans;
    }
};