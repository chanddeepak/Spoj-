#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
bool visited[10002];
int maxl=0,j;

void dfs(vector<int>* edges,int u,int count) {
    visited[u]=true;
    for(int i=0;i<edges[u].size();i++) {
        int v=edges[u][i];
        if(!visited[v]) {
            dfs(edges,v,count+1);
        }
        if(maxl<=count) {
            maxl=count;
            j=u;
     }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>* edges=new vector<int>[n+1];
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    dfs(edges,1,0);
    //cout<<maxl<<" "<<j<<" ";
    for(int i=0;i<=n;i++)
    visited[i]=false;
    dfs(edges,j,0);
    cout<<maxl<<"\n";
    return 0;
}