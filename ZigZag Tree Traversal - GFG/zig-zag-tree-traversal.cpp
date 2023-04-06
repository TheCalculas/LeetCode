//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
#define ll long long
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
#define _d(x) cerr << #x << " : " << x << endl;
#define out(v) for (auto &x : v) cout << x << " ";
#define set_bits(x) __builtin_popcountll(x)
#define endl '\n'
#define MOD 1000000007 // 998244353
const string yes = "YES";
const string no = "NO";
#define null NULL
#define r right
#define l left 
#define no Node
#define tn TreeNode
#define val data
#define pb(x) push_back(x) 
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        if(root==null) return {};
    	// Code here
    	// ye bhi breadth first search se karna hai 
    	vi vv;
    	int i = 0;
    	queue<no*> q;
    	q.push(root);
    	while(q.size())
    	{
    	    vi v;
    	    int n = q.size();
    	    while(n--)
    	    {
    	        auto x = q.front();
    	        q.pop();
    	        v.pb(x->val);
    	        if(x->l) q.push(x->l);
    	        if(x->r) q.push(x->r);
    	        
    	    }
    	    if(i%2)
    	    {
    	        revv(v);
    	        
    	    }
    	    i++;
    	    for(auto x: v) vv.pb(x);
    	   
    	}
    	return vv;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends