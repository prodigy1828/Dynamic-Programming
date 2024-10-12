#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

void solve(){
    int n ;
    string s;
    cin>>s;
    n = s.size();
    
    int prefix[n+1];//sum of dp[0.....i]
    int last[26];
    int dp[n+1];//unique subsequnce ending at i-1 of string 
    memset(last,-1,sizeof(last));
    dp[0]=1;
    prefix[0]=1;
    for(int i=1;i<=n;i++){
        //add after all characted
        dp[i]=prefix[i-1];
        if(last[s[i-1]-'a']!=-1){
            //remove all the duplicates
            int idx = last[s[i-1]-'a'];
            dp[i]-=prefix[idx];
        }
        //update this as the last index where this character is present
        last[s[i-1]-'a'] = i-1;
        //keep building the the prefix sum
        prefix[i]=prefix[i-1]+dp[i];
    }
    // -1 to remove the " " present at dp[0]  
    cout<<prefix[n]-1<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc;cin>>tc;while(tc--)
    solve();
}
























 
