#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

long cal(vector<long> &H,int n) {
	int i=0;
	long mA=0;
	stack<int> s;
	while(i<n) {
		if(s.empty()||H[s.top()]<=H[i])
			s.push(i++);
		else {
			int t=s.top();
			s.pop();
			long a=H[t]*(s.empty()?i:i-s.top()-1);
			if(mA<a)
				mA=a;
		}
	}
	while(!s.empty()) {
		int t=s.top();
		s.pop();
		long a=H[t]*(s.empty()?i:i-s.top()-1);
			if(mA<a)
				mA=a;
	}
	return mA;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n) {
    	if(n==0)
    		break;
    	vector<long> H(n);
    	for(int i=0;i<n;i++) 
    		cin>>H[i];
    	long ans=cal(H,n);
    	cout<<ans<<"\n";
    }
    return 0;
}