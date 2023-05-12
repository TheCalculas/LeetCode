//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        bool zeroPresent = false;
        for(auto x: arr) if(x==0) zeroPresent = true;
        if(zeroPresent == false) return -1;
        int one = 0;
        int cnt = 0;
        for(auto x: arr)
        {
            if(x==0)
            {
                if(one==1) {
                    cnt ++;
                    one = 0;
                }
            }
            else{
                one = 1;
            }
        }
        if(one ) cnt++;
        return cnt;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends