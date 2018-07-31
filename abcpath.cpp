#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int A[51][51],dist[51][51],H,W;

bool in_range(int x, int y) {
	if(x < H && y < W&& x >= 0 && y >= 0)
		return true;
	return false;
}

void dfs(int i,int j,int d) {
	int x, y;
	dist[i][j] = d+1;
	
	x = i-1;
	y = j-1;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
	x = i-1;
	y = j;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
	x = i-1;
	y = j+1;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
	x = i;
	y = j-1;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
	x = i;
	y = j+1;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
	x = i+1;
	y = j-1;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
	x = i+1;
	y = j;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
	x = i+1;
	y = j+1;
	if(in_range(x, y) && A[x][y] == A[i][j] + 1 && dist[x][y] < dist[i][j] + 1){
		dfs(x, y, dist[i][j]);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c=1;
    while(cin>>H>>W) {
    	if(H==0&&W==0)
    		break;
    	for(int i=0;i<H;i++) {
    		string s;
    		cin>>s;
    		for(int j=0;j<W;j++){
    			A[i][j]=s[j]-'A';
    			dist[i][j]=0;
    		}
    	}
    	for(int i=0;i<H;i++) {
    		for(int j=0;j<W;j++) {
    			if(A[i][j]==0&&dist[i][j]==0)
    				dfs(i,j,0);
    		}
    	}
    	int ans=0;
    	for(int i=0;i<H;i++) {
    		for(int j=0;j<W;j++) {
    			if(ans<dist[i][j])
    				ans=dist[i][j];
    		}
    	}
    	cout<<"Case "<<c<<": "<<ans<<"\n";
    	c++;
    	
    }
    return 0;
}