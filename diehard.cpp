#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int dp[1010][1010];

int cal(int H,int A,bool f,int c) {
	if(H<=0||A<=0)
		return c;
	if(dp[H][A]!=-1)
		return dp[H][A];
	if(f)
		dp[H][A]=max(dp[H][A],cal(H+3,A+2,!f,c+1));
	return dp[H][A]=max(dp[H][A],max(cal(H-5,A-10,!f,c+1),cal(H-20,A+5,!f,c+1)));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int H,A;
    	cin>>H>>A;
    	bool f=1;
    	for(int i=0;i<1010;i++) {
    		for(int j=0;j<1010;j++)
    			dp[i][j]=-1;
    	}
    	int ans=cal(H,A,f,-1);
    	cout<<ans<<"\n";
    }
    return 0;
}