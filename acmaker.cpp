#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;

int dp[50][50][50];

string toLowerC(string s) {
	for (int i=0;i<s.length();i++) s[i]^=32;
	return s;
}

int findWays(string &ab,vector<string> &words,int i,int j,int l) {
	if(i==ab.length()&&j==words.size()-1)
		return 1;
	if(i==ab.length()||j==words.size())
		return 0;
	if(dp[i][j][l]!=-1)
	    return dp[i][j][l];
	string s=words[j];
	int ans=0;
	for(int k=l;k<s.size();k++) {
		if(ab[i]==s[k]) {
			ans+=findWays(ab,words,i+1,j,k+1);
		}
	}
	if(l)
		ans+=findWays(ab,words,i,j+1,0);
	return dp[i][j][l]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1) {
	    int n;
	    cin>>n;
	    if(n==0)
	    	break;
	    set<string> insignificant;
	    for(int i=0;i<n;i++) {
	    	string s1;
	    	cin>>s1;
	    	insignificant.insert(s1);
	    }
	    int f=0;
	    while(1) {
	    	string acro; cin >> acro; cin.ignore();
            string phrase; getline(cin, phrase);
            if (phrase == "CASE") break;
            istringstream iss(phrase);
            vector<string> words;
            for (;;) {
                string word; iss >> word;
                if (word == "") break;
                if (insignificant.find(word) == insignificant.end()) {
                    words.push_back(word);
                }
            }
	    	string ab=toLowerC(acro);
	    	memset(dp,-1,sizeof(dp));
	    	int ans=findWays(ab,words,0,0,0);
	    	if(ans)
	    	    cout<<acro<<" can be formed in "<<ans<<" ways\n";
	    	else 
	    	    cout<<acro<<" is not a valid abbreviation\n";
	    }
	}
    return 0;
}