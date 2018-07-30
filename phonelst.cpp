#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

struct Trie {
	Trie** next;
	bool end;
	Trie() {
		next = new Trie*[10];
		for(int i=0;i<10;i++)
			next[i]=NULL;
		end=false;
	}
};

bool insertTrie(string &s,Trie* root) {
	if(s.empty()) {
		root->end=true;
		for(int i=0;i<10;i++) {
			if(root->next[i])
				return true;
		}
		return false;
	}
	if(root->end)
		return true;
	Trie* child;
	int i=s[0]-'0';
	if(root->next[i]) {
		child=root->next[i];
	} else {
		child = new Trie();
		root->next[i]=child;
	}
	return insertTrie(s.substr(1),child);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	bool ans=false;
    	while(n--) {
    		string s;
    		cin>>s;
    		if(!ans) {
    			Trie* root = new Trie();
    			if(insertTrie(s,root))
    				ans=true;
    		}
    	}
    	if(ans)
    		cout<<"NO\n";
    	else
    		cout<<"YES\n";
    }
    return 0;
}