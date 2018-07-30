#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int merge(int* A,int l,int m,int r) {
	int i=l,j=m,k=0,c=0;
	int temp[r-l+1];
	while(i<mid&&j<=r) {
		if(A[i]<=A[j]) {
			temp[k++]=A[i++];
		} else {
			temp[k++]=A[j++];
			c+=mid-i;
		}
	}
	while(i<mid) {
		temp[k++]=A[i++];
	}
	while(j<=r) {
		temp[k++]=A[j++];
	}
	for(int i=l,j=0;i<=r;i++,j++) {
		A[i]=temp[j];
	}
	return c;
}

int mergeSort(int* A,int l,int r) {
	if(l>r)
		return 0;
	int ans=0;
	int m=(l+r)/2;
	ans+=mergeSort(A,l,m);
	ans+=mergeSort(A,m+1,r);
	ans+=merge(A,l,m,r);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	int A[n];
    	for(int i=0;i<n;i++) {
    		cin>>A[i];
    	}
    	int ans=mergeSort(A,0,n-1);
    	cout<<ans<<"\n";
    }
    return 0;
}