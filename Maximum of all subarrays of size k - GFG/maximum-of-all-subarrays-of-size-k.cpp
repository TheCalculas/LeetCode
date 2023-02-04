//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // implemented deque
         deque<int> dq;
         vector<int> v;
         
          for (int i = 0; i < n; i++) {
// if greater element appers then i will pop previous element
            while (!dq.empty() && arr[i] >= arr[dq.back()])
              dq.pop_back();
            // push toh karna hee hai abhi toh
            dq.push_back(i);
            // agar k elements ho gaye hai joki init condition thi phele 
            if (i >= k - 1) {
            // abh dekh first element is the largest toh vahi ans hoga
              v.push_back(arr[dq.front()]);
              // iska matalbh hai ki basically iska time ho chuka hai 
              // toh ise pop kardo abh koi kaam nhi hai iska 
              if (dq.front() <= i - k + 1)
                dq.pop_front();
                }
            }
        // cout <<endl;
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends