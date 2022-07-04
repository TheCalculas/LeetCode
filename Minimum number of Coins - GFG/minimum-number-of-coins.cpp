// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int price[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n = 9;
        vector<int> v;
        while(N&&n>=0)
        {
            while(price[n]>N) n--;
            if(n<0) return v;
            v.push_back(price[n]);
            N = N - price[n];
        }
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends