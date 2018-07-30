#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const int MAX=1000002;
long etf[MAX];

void ETF() {
	for(int i=0;i<MAX;i++)
		etf[i]=i;
	for(int i=2;i<MAX;i++) {
		if(etf[i]==i) {
			etf[i]=etf[i]-1;
			for(long j=2*i;j<MAX;j+=i) {
				etf[j]=(etf[j]*(i-1))/i;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ETF();
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	cout<<etf[n]<<"\n";
    }
    return 0;
}