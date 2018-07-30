#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

void multiply(long A[2][2],long M[2][2]) {
	long m[2][2];
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			m[i][j]=0;
			for(int k=0;k<2;k++) {
				m[i][j]=(m[i][j]+A[i][k]*M[k][j])%MOD;
			}
		}
	}
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			A[i][j]=m[i][j];
		}
	}
}

void power(long A[2][2],long n) {
	if(n==1)
		return;
	power(A,n/2);
	multiply(A,A);
	if(n%2!=0) {
		long F[2][2]={{1,1},{1,0}};
		multiply(A,F);
	}
}

long fib(long n) {
	if(n==0||n==1)
		return n;
	long A[2][2]={{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}

long fiboSum(long n,long m) {
	//Sum = S(m)-S(n-1)=F(m+2)-1-(F(n+1)-1)
	long sum=((fib(m+2)-fib(n+1))%MOD+MOD)%MOD;
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	long n,m;
    	cin>>n>>m;
    	long ans=fiboSum(n,m);
    	cout<<ans<<"\n";
    }
    return 0;
}