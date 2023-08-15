//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
// custom defines for functions and datatypes ---------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i>=b; i--)
#define sortv(v) sort(v.begin(), v.end())
#define rsortv(v) sort(v.rbegin(), v.rend())
#define revv(v) reverse(v.begin(), v.end())
#define _l cout << "+------------+" << endl;
#define _p(x) cout << #x << " : " << x << endl;
#define out(v) for (auto &x : v) cout << x << " ";
#define set_bits(x) __builtin_popcountll(x)
#define endl '\n'
#define MOD 1000000007 // 998244353
const string yes = "YES";
const string no = "NO";

// custom declarations ----------------------------------------
#define null NULL
#define r right
#define l left 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second


// Debugging Statements ----------------------------------------
#ifndef ONLINE_JUDGE
#define _d(x) cout<< #x <<" : "; _print(x); cout<< endl;
#else
#define _d(x)
#endif

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

bool cmp(pair<int, int> &a, pair<int, int>&b)
{
    
        return a.second>b.second;
   
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vii v;
        rep(i, 0, n)
        {
            v.pb({arr[i].dead, arr[i].profit});
        }
        sort(v.begin(), v.end(), cmp);
        vi vis(n, 0);
        int cnt  = 0;
        int prof = 0;
        // _print(v);
        rep(i, 0, n)
        {
            // decreasing with the deadline
            rrep(j, v[i].first-1, 0)
            {
                if(vis[j]==1) continue;
                
                else{
                    vis[j] =1;
                    cnt++;
                    prof+=v[i].second;
                    break;
                }
            }
        }
        return { cnt, prof};
        // your code here
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends