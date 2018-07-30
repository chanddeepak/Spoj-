#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int p;

bool mooreVotingAlgo(vector<int> &A,int n) {
	int majInd=0,c=1;
	for(int i=1;i<n;i++) {
		if(A[majInd]==A[i]) {
			c++;
		} else {
			c--;
		}
		if(c==0) {
			majInd=i;
			c=1;
		}
	}
	int ans=0;
	p=A[majInd];
	for(int i=0;i<n;i++) {
		if(p==A[i]) {
			ans++;
			if(ans>n/2) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	vector<int> A(n);
    	for(int i=0;i<n;i++) 
    		cin>>A[i];
    	p=0;
    	if(mooreVotingAlgo(A,n)) {
    		cout<<"YES"<<" "<<p<<"\n";
    	} else{
    		cout<<"NO\n";
    	}

    }
    return 0;
}