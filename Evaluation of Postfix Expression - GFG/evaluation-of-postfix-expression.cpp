//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        stack<int> st;
        for(auto x: s)
        {
            if(x=='*')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = a*b;
                st.push(res);
            }
            else if(x=='+')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = a+b;
                st.push(res);
            }
            else if(x=='-')
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = a-b;
                st.push(res);
            }
            else if(x=='/')
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = a/b;
                st.push(res);
            }
            else{
                st.push(x-'0');
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends