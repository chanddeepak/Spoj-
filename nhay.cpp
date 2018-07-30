#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

void computeLPSArray(string &pat,vector<long> &lps,long n) {
	long len=0;
	lps[0]=0;
	int i=1;
	while(i<n) {
		if(pat[i]==pat[len]) {
			len++;
			lps[i]=len;
			i++;
		} else {
			if(len!=0) {
				len=lps[len-1];
			} else {
				lps[i]=0;
				i++;
			}
		}
	}
}

void KMPSearch(string &pat,string &txt,vector<long> &lps,int n) {
	int m=txt.size();
	int i=0,j=0;
	while(i<m) {
		if(txt[i]==pat[j]) {
			i++;
			j++;
		}
		if(j==n) {
			cout<<i-j<<"\n";
			j=lps[j-1];
		} else if(i<m&&txt[i]!=pat[j]) {
			if(j!=0) {
				j=lps[j-1];
			} else {
				i++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n) {
    	string s,s1;
    	cin>>s>>s1;
    	vector<long> lps(n);
    	computeLPSArray(s,lps,n);
    	KMPSearch(s,s1,lps,n);
    	cout<<"\n";
    }
    return 0;
}