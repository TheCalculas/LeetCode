// { Driver Code Starts
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









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftTraversal(Node *root, vector<int> &ans){
        if(root->left != NULL || root->right != NULL)
            ans.push_back(root->data);
        if(root->left)
            leftTraversal(root->left, ans);
        else if(root->left == NULL && root->right)
            leftTraversal(root->right, ans);
    }
    void leafNode(Node *root, vector<int> &ans){
        if(root->left == NULL && root->right == NULL)
            ans.push_back(root->data);
        if(root->left)
            leafNode(root->left, ans);
        if(root->right)
            leafNode(root->right, ans);
        
    }
    void rightTraversal(Node *root, stack<int> &temp){
        if(root->left != NULL || root->right != NULL)
            temp.push(root->data);
        if(root->right)
            rightTraversal(root->right, temp);
        else if(root->right == NULL && root->left){
            rightTraversal(root->left, temp);
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        stack<int> temp;
        ans.push_back(root->data);
        if(root->left) //left boundary node except leaf node
            leftTraversal(root->left, ans);
            
        if(root->left != NULL || root->right != NULL)
        leafNode(root, ans); // this is an inorder traversal for leaf node
        
        if(root->right) // right boundary node except right node in reverse order
            rightTraversal(root->right, temp); // that's why we used a stack here
        
        while(!temp.empty()){ // copying the value of stack to vector.
            int t = temp.top();
            ans.push_back(t);
            temp.pop();
        }
        return ans;
        //Your code here
    }
};
 

// { Driver Code Starts.

/* Driver program to test size function*/

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
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends