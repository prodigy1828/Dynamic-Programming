#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

void solve(){
    int n ;
    string s;
    cin>>s;
    n = s.size();
    
    int prefix[n+1];
    int last[26];
    int dp[n+1];
    memset(last,-1,sizeof(last));
    dp[0]=1;
    prefix[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=prefix[i-1];
        if(last[s[i-1]-'a']!=-1){
            int idx = last[s[i-1]-'a'];
            dp[i]-=prefix[idx];
        }
        last[s[i-1]-'a'] = i-1;
        prefix[i]=prefix[i-1]+dp[i];
    }
    cout<<prefix[n]-1<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc;cin>>tc;while(tc--)
    solve();
}
























 
