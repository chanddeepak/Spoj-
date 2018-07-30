#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n) {
    	if(n==0)
    	break;
	    vector<int> A(n),cnt(n+2,0);
	    for(int i=0;i<n;i++) {
	    	cin>>A[i];
	    	cnt[A[i]]++;
	    }
	    stack<int> sl;
	    for(int i=0;i<A.size();i++) {
	    	sl.push(A[i]);
	    	//cout<<A[i]<<" ";
	    	if(cnt[A[i]-1]==0&&!sl.empty()) {
	    		int a=sl.top();
	    		cnt[a]--;
	    		sl.pop();
	    		while(!sl.empty()) {
	    			int b=sl.top();
	    			if(b==a||b==a+1) {
	    				sl.pop();
	    				a=b;
	    				cnt[a]--;
	    			} else {
	    				break;
	    			}
	    		}
	    	}
	    }
	    if(sl.empty())
		cout<<"yes\n";
		else
		cout<<"no\n";
    }
    return 0;
}