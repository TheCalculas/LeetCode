//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


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
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
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

bool flag = true;
class Solution{
    public:
    int h(no* root)
    {
        if(root==null) return 0;
        int a= h(root->l);
        int b = h(root->r);
        if(abs(a-b)>1) flag = false;
        return 1 + max(a, b);
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        flag = true;
        //  Your Code here
        h(root);
        return flag;
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
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends