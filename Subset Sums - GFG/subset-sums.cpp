//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

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

class Solution
{
public:
    void f(vi &v, int n, int idx, vi &res, int curr)
    {
        if(idx==n)
        {
            res.pb(curr);
            return;
        }
        f(v, n, idx+1, res, curr);
        f(v, n, idx+1, res, curr+v[idx]);
    }
    vector<int> subsetSums  (vector<int> arr, int N)
    {
        // Write Your Code her
        vi res;
        int curr = 0;
        f(arr, N, 0, res, curr);
        return res;
    }
};














//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends