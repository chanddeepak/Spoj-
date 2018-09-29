#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int dp[1000010];
bool cal(int A,int k,int l) {
	if(dp[A]!=-1) {
		return dp[A]==1?1:0;
	}
	if(A==0) {
		dp[A]=2;
		return false;
	}
	if(A==1||A==k||A==l) {
		dp[A]=1;
		return true;
	}
	if(!cal(A-1,k,l)||(A-k>=0&&!cal(A-k,k,l))||(A-l>=0)&&!cal(A-l,k,l)) {
		dp[A]=1;
		return true;
	}
	dp[A]=2;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<1000002;i++)
	dp[i]=-1;
    int k,l,m,a;
    cin>>k>>l>>m;
    for(int i=0;i<m;i++) {
    	cin>>a;
    	if(cal(a,k,l)) {
    		cout<<'A';
    	} else  {
    		cout<<'B';
    	}
    }
    cout<<"\n";
    return 0;
}