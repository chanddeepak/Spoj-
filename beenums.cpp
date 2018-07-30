#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

bool bs(long n) {
	long l=0,r=1e9;
	while(l<=r) {
		long m=(l+r)/2;
		long p=1+3*m*(m+1);
		if(p==n) 
			return true;
		else if(p>n) 
			r=m-1;
		else 
			l=m+1;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    while(1) {
    	long n;
    	if(n==-1)
    		break;
    	cin>>n;
    	if(bs(n))
    	cout<<"Y\n";
    	else 
    	cout<<"N\n";
    }
    return 0;
}