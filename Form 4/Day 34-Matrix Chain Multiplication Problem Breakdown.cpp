#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
int x[101],y[101];
int dp[101][101];

int rec(int l,int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int ans = INF;
    for(int mid=l;mid<r;mid++){
        ans = min(ans,rec(l,mid)+rec(mid+1,r)+x[l]*y[mid]*y[r]);
    }
    return dp[l][r]=ans;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
