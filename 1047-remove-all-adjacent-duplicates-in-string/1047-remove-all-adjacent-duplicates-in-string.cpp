class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(st.size()&&st.top()==s[i]) st.pop();
            else{
                st.push(s[i]);
            }
        }
        string a ="";
        while(st.size()) {
            a.push_back(st.top());
            st.pop();
        }
        reverse(begin(a), end(a));
        return a;
    }
};