#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;

int dp[5050];
int acode(string &s,int i,int n) {
    if(s[i]=='0') 
        return 0;
    if(i==n||i==n-1)
        return 1;
    if(dp[i]!=-1)
        return dp[i];
    int ans=acode(s,i+1,n);
    int a=s[i]-'0',b=s[i+1]-'0';
    int c=a*10+b;
    if(c<=26&&c>9) {
        ans+=acode(s,i+2,n);
    }
    return dp[i]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    while(s!="0") {
    	memset(dp,-1,sizeof(dp));
    	int n=s.size();
    	int ans=acode(s,0,n);
    	cout<<ans<<"\n";
    	cin>>s;
    }
    return 0;
}