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
   		vector<int> A(n);
   		for(int i=0;i<n;i++)
   			cin>>A[i];
   		int m;
   		cin>>m;
   		vector<int> B(m);
   		for(int i=0;i<m;i++)
   			cin>>B[i];
   		int i=0,j=0,sa=0,sb=0,ans=0;
   		while(1) {
   			if(i<n&&j<m&&A[i]<B[j]) {
   				sa+=A[i];
   				i++;
   			} else if(i<n&&j<m&&B[j]<A[i]) {
   				sb+=B[j];
   				j++;
   			} else if(i<n&&j<m&&B[j]==A[i]) {
   				ans+=max(A[i]+sa,B[j]+sb);
   				sa=0;
   				sb=0;
   				i++;
   				j++;
   			}
   			if(i>=n&&j>=m)
   				break;
   			if(i>=n) {
   				while(j<m) {
   					sb+=B[j];
   					j++;
   				}
   				ans+=max(sa,sb);
   				break;
   			}
   			if(j>=m) {
   				while(i<n) {
   					sa+=A[i];
   					i++;
   				}
   				ans+=max(sa,sb);
   				break;
   			}
   		}
   		cout<<ans<<"\n";
   	}
    return 0;
}