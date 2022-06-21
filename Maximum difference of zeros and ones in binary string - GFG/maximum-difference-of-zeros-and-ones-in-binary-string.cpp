// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int count = 0;
	    int result = 0;
	    
	    for(int i=0; i<S.size(); i++){
	        if(S[i] == '1'){
	            if(count > 0){
	                count--;
	            }
	        }
	        else{
	            count++;
	        }
	        result = max(result, count);
	    }
	    
	    if(result > 0){
	        return result;
	    }
	    else{
	        return -1;
	    }
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends