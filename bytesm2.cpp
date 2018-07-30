#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int dp[102][102];

int philStone(int** stones,int i,int j,int w) {

	if(i<0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j]; 
	int a=stones[i][j]+philStone(stones,i-1,j,w);
	int b=0;
	if(j+1<w)
		b=stones[i][j]+philStone(stones,i-1,j+1,w);
	int c=0;
	if(j-1>=0)
		c=stones[i][j]+philStone(stones,i-1,j-1,w);
		//cout<<a<<" "<<b<<" "<<c<<" ";
	int ans=max(max(a,b),c);

	return dp[i][j]=ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int h,w;
    	cin>>h>>w;
    	int** stones=new int*[h];
    	for(int i=0;i<h;i++) {
    		stones[i]=new int[w];
    		for(int j=0;j<w;j++)
    			cin>>stones[i][j];
    	}
    	for(int i=0;i<=h;i++) {
    		for(int j=0;j<=w;j++)
    			dp[i][j]=-1;
    	}
    	int max=0;
    	for(int i=0;i<w;i++) {
    		int ans=philStone(stones,h-1,i,w);
    		if(max<ans)
    			max=ans;
    	}
    	// for(int i=0;i<h;i++) {
    	// 	for(int j=0;j<w;j++)
    	// 		cout<<dp[i][j]<<" ";
    	// 		cout<<"\n";
    	// }
    	cout<<max<<"\n";
    }
    return 0;
}