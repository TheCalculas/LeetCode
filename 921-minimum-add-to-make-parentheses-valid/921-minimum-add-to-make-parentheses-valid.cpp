class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto x:s)
        {
            if(x=='(')
            {
                st.push('(');
            }
            else if(x==')'){
                if(st.size()&&st.top()=='(') st.pop();
                else st.push(')');
            }
        }
        return st.size();
    }
};