#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
string t="0100";
int dp[100100][8];

int rec(int level,int lastthree){
    //pruning
    //basecase
    if(level==n) return 1;
    //cache check
    if(dp[level][lastthree]!=-1) return dp[level][lastthree];
    //transition
    int ans = 0 ;
    if(lastthree==2 && level>=3){
        //ie.010 ->don't allow 
        ans = rec(level+1,5);
    }else{
        //add a zero
        ans = rec(level+1,((lastthree<<1)|0)&(7));
        ans+=rec(level+1,((lastthree<<1)|1)&(7));
    }
    //save anf return
    return dp[level][lastthree]=ans;
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














 