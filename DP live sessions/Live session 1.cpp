#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int dp[1001][1001];
int n,k;

int rec(int i,int d,int seenk){
    //pruning
    if(d<0||d>k) return 0;
    //base case
    if(i==n){
        if(d==0 && seenk==1) return 1;
        else return 0;
    }
    //cache check
    if(dp[i][d][seenk]!=-1) return dp[i][d][seenk];
    //compute
    int ans  = rec(i+1,d+1,seenk||(d+1==k)) + rec(i+1,d-1,seenk);
    //save return
    return dp[i][d][seenk]=ans; //TC->O(N*K)
}

void solve(){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}







