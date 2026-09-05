class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        int res = INT_MAX;
        for(int i=0; i<text.size(); i++ ){
            have[text[i]]++;
        }
        unordered_map<char,int>make;
        make['b'] = 1;
        make['a'] = 1;
        make['l'] = 2;
        make['o'] = 2;
        make['n'] = 1;
        for(auto i : make){
            char c = i.first;
            int fhave = have[c];
            int fneed = i.second;
            int time = fhave/fneed;
            res = min(res,time);
        }
        return res;
    }
};