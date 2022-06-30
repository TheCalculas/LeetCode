class Solution {
public:
    int n;
    string S;
    unordered_set<string> st;
    vector<string> ans;
    
    void solve(int i,string& s,string& curr){
        if(i == n){
            if(st.find(curr) != st.end()){
                ans.push_back(s);
            }
        }else{
            if(st.find(curr) != st.end()){
                s += " ";
                s += S[i];
                string temp = "";
                temp += S[i];
                solve(i+1,s,temp);
                s.pop_back();
                s.pop_back();
            }
            s += S[i];
            curr += S[i];
            solve(i+1,s,curr);
            curr.pop_back();
            s.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        S = s;
        for(auto i:wordDict){
            st.insert(i);
        }
        s = "";
        string curr = "";
        solve(0,s,curr);
        return ans;
    }
};