#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
bool visited[10002];

bool dfs(vector<int>* adj,int u,int parent) {
	visited[u]=true;
	for(int i=0;i<adj[u].size();i++) {
		int v=adj[u][i];
		if(!visited[v]) {
			if(dfs(adj,v,u))
				return true;
		} else if(v!=parent)
			return true;
	}
	return false;
}
bool isCycle(vector<int>* adj,int n) {
	for(int i=1;i<=n;i++) {
    		if(!visited[i])
    			if(dfs(adj,i,-1))
    			return true;
	}	
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>* adj=new vector<int>[n+2];
    for(int i=0;i<m;i++) {
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    if(isCycle(adj,n))
    	cout<<"NO\n";
    else
    	cout<<"YES\n";
    return 0;
}