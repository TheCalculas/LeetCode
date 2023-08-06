//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void f(string s, int idx, vector<string>&v)
    {
        if(idx>=s.size())
        {
            v.push_back(s);
            return;
        }
        
        for(int i = idx; i<s.size(); i++)
        {
            swap(s[i], s[idx]);
            f(s, idx+1, v);
            swap(s[i], s[idx]);
        }
        
    }
    vector<string> permutation(string s)
    {
        //Your code here
        vector<string> v;
        f(s, 0, v);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends