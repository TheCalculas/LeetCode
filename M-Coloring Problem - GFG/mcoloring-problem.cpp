// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[][101], int col, int a, int m, int n, vector<int> &color)
{
    for(int i=0; i<n; i++)
    if(graph[i][a]==1&&color[i]==col&&a!=i) return false;
    return true;
}


bool help(bool graph[][101], int a, int m, int n, vector<int> &color)
{
    if(a==n)
        return true;
    for(int i=1; i<=m; i++)
    {
        if(isSafe(graph, i, a, m, n, color))
        {
            color[a] = i;
            if (help(graph, a+1, m, n, color))return true;
            color [a] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, 0); // it is the color of the nth vertex
    return help(graph, 0, m, n, color);
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends