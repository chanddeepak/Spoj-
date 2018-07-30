#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;

bool cmp(int a,int b) {
	return a>b;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    for(int j=1;j<=k;j++) {
	    int n,t;
	    cin>>n>>t;
	    vector<int> v(t);
	    for(int i=0;i<t;i++)
	    	cin>>v[i];
	    sort(v.begin(),v.end(),cmp);
	    int ans=0,s=0,f=0;
	    for(int i=0;i<t;i++) {
	    	s+=v[i];
	    	if(s>=n) {
	    		ans=i+1;
	    		f=0;
	    		break;
	    	}
	    	f=1;
	    }
	    cout<<"Scenario #"<<j<<":\n";
	    if(f==1)
	    cout<<"impossible\n";
	    else
	    cout<<ans<<"\n";
	}
    return 0;
}