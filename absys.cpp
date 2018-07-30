#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s,s1="machula";
        
        int num1,num2,f,t=0;
        for(int i=0;i<=4;i++) {
        	s="";
            cin>>s;
           
            if(s.find(s1) != std::string::npos) {
                f=i;
            } else if(s!="+"&&s!="=") {
            	
                if(t==0) {
                
                    num1=stoi(s);
                    t++;
                    
                    continue;
                }
                num2=stoi(s);
               
            }
        }
        if(f==0) {
            cout<<num2-num1<<" + "<<num1<<" = "<<num2<<"\n";
        } else if(f==2) {
            cout<<num1<<" + "<<num2-num1<<" = "<<num2<<"\n";
        } else {
            cout<<num1<<" + "<<num2<<" = "<<num1+num2<<"\n";
        }
    }
    
    return 0;
}