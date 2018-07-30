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
    long t;
    cin>>t;
    if(t%10==0) {
    	cout<<"2\n";
    	return 0;
    }
    cout<<"1\n";
    cout<<t%10;
    return 0;
}