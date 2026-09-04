class Solution {
public:
    bool isValid(string s) {
        stack <int> st;
        for(char c : s){
            if(c == '[' || c == '{' || c == '('){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char topi = st.top();
                if((c == ']' && topi == '[') || (c == '}' && topi == '{' )||( c == ')' && topi == '(')) {
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};