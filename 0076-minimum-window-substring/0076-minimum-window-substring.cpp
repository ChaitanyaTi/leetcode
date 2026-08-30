class Solution {
public:
    bool fun(vector<int> &have, vector<int> &want){
        for(int i =0; i< 256; i++){
            if(have[i] < want[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int>have(256,0);
        vector<int>want(256,0);
        int mini = INT_MAX;
        if(n<m){
            return "";
        }
        for(int i =0; i<t.size(); i++){
            want[t[i]]++;
        }
        int left = 0;
        int right = 0;
        int start = -1;
        for(int right = 0; right<s.size(); right++){
            have[s[right]]++;
            while(fun(have,want)){
                int len = right - left + 1;
                if(len<mini){
                    mini = len;
                    start = left;
                }
                have[s[left]]--;
                left++;
            }
            
        }
        if(mini == INT_MAX){
                return "";
        }
        return s.substr(start,mini);
    }
};