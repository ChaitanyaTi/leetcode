class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>f;
        for(int i =0; i<s.size(); i++){
            f[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it : f){
            pq.push({it.second,it.first});
        }
        string res = "";
        while(!pq.empty()){
            pair<int,char>p = pq.top();
            pq.pop();
            if(res.empty() || res.back() != p.second){
                res += p.second;
                p.first--;
                if(p.first > 0){
                    pq.push(p);
                }
            }
            else{
                if(pq.empty()){
                    return "";
                }
                else{
                    pair<int,char>p1 = pq.top();
                    pq.pop();
                    res += p1.second;
                    p1.first--;
                    if(p1.first > 0){
                        pq.push(p1);
                    }
                    pq.push(p);
                }
            }
        }
        return res;
    }
};