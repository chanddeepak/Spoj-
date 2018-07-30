#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    //unordered_map<int,int> um,um1;
    vector<int> v1,v2;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                int ans1=A[j]*A[k]+A[i];
            	//um[ans1]++;
            	v1.pb(ans1);
                if(A[i]!=0) {
                    int ans2=(A[j]+A[k])*A[i];
            //	um1[ans2]++;
            	v2.pb(ans2);
                }
            }
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int ans=0;
    for(int i=0;i<v1.size();i++) {
        auto u=equal_range(v2.begin(),v2.end(),v1[i]);
        ans+=(u.second-v2.begin())-(u.first-v2.begin());
    }
    cout<<ans<<"\n";
    return 0;
}