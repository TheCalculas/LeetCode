//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector<int> diagonal(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
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
#define no Node
#define tn TreeNode
#define val data
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

// +----------------------+

void inorder(no* root, int r1, map<int,vi>&mp)
{
    if(root==null) return;
    mp[r1].pb(root->val);
    inorder(root->left, r1+1, mp);
    inorder(root->right, r1, mp);
}


vector<int> diagonal(Node *root)
{
    // do the preorder traversal for this tree
    map<int,vi> mp;
    inorder(root, 0, mp);
    vi v;
    for(auto x: mp)
    {
        for(auto y: x.second) v.pb(y);
    }
    return v;
}