//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // vector<pair<int, int>> graph[V];
        
        // for(int i =0; i<adj.size(); i++)
        // {
        //     for(int j = 0; j<adj[i].size(); i++)
        //     {
                
        //     }
        // }
        
        
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        priority_queue<
        pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;
        pq.push({0, S}); // node, dist
        
        while(pq.size())
        {
            auto a = pq.top(); pq.pop();
            int srcdist = a.first;
            for(auto x: adj[a.second])
            {
                // node, weight
                int distance = srcdist + x[1];
                if(distance<dist[x[0]])
                {
                    dist[x[0]] = distance;
                    pq.push({distance, x[0]});
                }
            }
            
        }
        return dist;

    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends