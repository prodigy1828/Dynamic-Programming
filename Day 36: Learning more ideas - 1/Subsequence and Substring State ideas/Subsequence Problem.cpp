#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
string t="0100";
int dp[100100][5];

int rec(int level,int match){
    //pruning
    if(match==4) return 0;
    //basecase
    if(level==n) return 1;
    //cache check
    if(dp[level][match]!=-1) return dp[level][match];
    //transition
    int ans = rec(level+1,match+1)+rec(level+1,match);
    //save anf return
    return ans= dp[level][match];
}

void solve(){
   cin>>n;
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,0)<<endl;
   
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
