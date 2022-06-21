// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int x = 0;
        for(auto a: nums) x^=a;
        // now we got the xor of a, b
        int set = 1;
        while(set<=x)
        {
            if(set&x) break;
            set<<=1;
        }
        // now we got the set bit of one number
        // finding that number
        int zor = 0;
        for(auto a:nums)
        {
            if(a&set)
            {
                zor^=a;
            }
        }
        // zor has the number bish
        vector<int> v;
        v.push_back(zor);
        x = x^zor;
        v.push_back(x);
        sort(v.begin(), v.end());
        return v;
        // Code here.
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends