//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &v , int n){
        // code here 
        int i = 0, j = 0;
        long long sum = 0;
        long long mx = 0;
        while(j<n)
        {
            sum+=v[j];
            if(j-i+1<k)
            {
                // window chhoti hai 
                // add karo
                // increment j
                j++;
            }
            else if(j-i+1==k){
                // window ki size == k
                mx = max(mx, sum); // calculations
                
                // window ko shift karo
                sum-=v[i];
                i++;
                j++;
                
                
                mx = max(mx, sum);
                
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends