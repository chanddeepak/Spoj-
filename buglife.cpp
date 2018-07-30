#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

bool isBipartite(vector<int>* adj,int s,vector<int> &color) {
	queue<int> q;
	q.push(s);
	color[s]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++) {
			int v=adj[u][i];
			if(color[v]==-1) {
				color[v]=1-color[u];
				q.push(v);
			} else if(color[u]==color[v])
				return false;
		}
	}
	return true;
}

bool bipartite(vector<int>* adj,int n) {
	vector<int> color(n+1);
    for(int i=1;i<=n;i++) 
    	color[i]=-1;
    for(int i=1;i<=n;i++) {
    	if(color[i]==-1) {
    		if(!isBipartite(adj,i,color))
    			return false;
    	}
    } 
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,j=1;
    cin>>t;
    while(t--) {
    	int n,m;
    	cin>>n>>m;
    	vector<int>* adj=new vector<int>[n+2];
    	for(int i=0;i<m;i++) {
    		int x,y;
    		cin>>x>>y;
    		adj[x].pb(y);
    		adj[y].pb(x);
    	}
    	cout<<"Scenario #"<<j<<":\n";
    	if(!bipartite(adj,n)) {
    		cout<<"Suspicious bugs found!\n";
    	}else {
    		cout<<"No suspicious bugs found!\n";
    	}
    	j++;
    }
    return 0;
}