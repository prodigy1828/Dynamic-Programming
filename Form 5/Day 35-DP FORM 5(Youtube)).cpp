#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
int n;
int dp[100100];

int rec(int x){
    //pruning->not here 
    //basecase
    if(x==0){
        return 0;
    }
    //cache check
    if(dp[x]!=-1) return dp[x];
    //compute
    int ans = 0 ;
    for(int m=0;(1<<m)<=x;m++){
        if(rec(x-(1<<m))==0) {// if at any 
            ans=1;
            break;
        }
    }
    //save and return
    return dp[x]=ans;
    
}

void solve(){

    //cin>>n;
    memset(dp,-1,sizeof(dp));
    //cout<<rec(n)<<endl;
    for(int i=0;i<=10;i++){
        cout<<i<<" "<<rec(i)<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
