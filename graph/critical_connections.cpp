#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis, vector<int> &low, vector<int> &tin, vector<vector<int>> &bridges){
    
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(vis[it])
            low[node] = min(low[node], low[it]);
        else{
            dfs(it, node, adj, vis, low, tin, bridges);
            low[node] = min(low[node], low[it]);
            
            if(low[it] > tin[node])
                bridges.push_back({it, node});
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &adj){
    vector<vector<int>> ans;
    vector<int> low(n);
    vector<int> tin(n);
    vector<int> vis(n, 0);
    
    dfs(0, -1, adj, vis, low, tin, ans);
    
    return ans;
}

int main() {
	int n,v;
	cin>>n>>v;
	vector<vector<int>> roads(v,vector<int>(2));
	for(int i=0;i<v;i++)
	    cin>>roads[i][0]>>roads[i][1];
	    
	vector<vector<int>> adj(n);
	for(int i=0;i<v;i++){
	    adj[roads[i][0] - 1].push_back(roads[i][1] - 1);
	    adj[roads[i][1] - 1].push_back(roads[i][0] - 1);
	}
	
	vector<vector<int>> ans = criticalConnections(n, adj);
	int x = ans.size();
	cout<<x<<"\n";
	for(int i=0;i<x;i++){
	    cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
	}
	return 0;   
}
