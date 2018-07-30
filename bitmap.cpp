#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int A[185][185],n,m;

void bfs(int i,int j) {
	queue<int> q;
	q.push(i);
	q.push(j);
	//cout<<i<<" "<<j<<" ";
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		int y=q.front();
		q.pop();
		int dist=A[x][y]+1;
		if(x-1>=0&&dist<A[x-1][y]) {
			q.push(x-1);
			q.push(y);
			A[x-1][y]=dist;
		}
		if(x+1<n&&dist<A[x+1][y]) {
			q.push(x+1);
			q.push(y);
			A[x+1][y]=dist;
		}
		if(y-1>=0&&dist<A[x][y-1]) {
			q.push(x);
			q.push(y-1);
			A[x][y-1]=dist;
		}
		if(y+1<m&&dist<A[x][y+1]) {
			q.push(x);
			q.push(y+1);
			A[x][y+1]=dist;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	cin>>n>>m;
    	vector<pair<int,int>> v;
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			char a;
    			cin>>a;
    			if(a=='1') {
    				A[i][j]=0;
    				v.pb(mp(i,j));
    			} else {
    				A[i][j]=1000;
    			}
    		}
    	}
    	for(int i=0;i<v.size();i++) {
    		bfs(v[i].first,v[i].second);
    	}
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++)
    			cout<<A[i][j]<<" ";
    		cout<<"\n";
    	}
    }
    return 0;
}