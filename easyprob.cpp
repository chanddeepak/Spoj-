#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

void cal(int n) {
	int a=n;
	if(a<4) {
		if(a==3) {
			cout<<"2+2(0)";
		} else if(a==2) {
			cout<<"2";
		} else if(a==1) {
			cout<<"2(0)";
		} 
		return;
	} 
	int i=0;
	while(a>0) {
		i++;
		a=a/2;
	}
	int b=pow(2,i-1);
	cout<<"2(";
	cal(i-1);
	cout<<")";
	if(n-b!=0) {
		cout<<"+";
		cal(n-b);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	cout<<n<<"=";
    	cal(n);
    	cout<<"\n";
    }
    return 0;
}