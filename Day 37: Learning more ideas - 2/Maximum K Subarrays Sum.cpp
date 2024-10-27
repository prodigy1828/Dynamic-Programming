#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9


int n,k;
int p[1001];
int dp[1001][1001];
int done[1001][1001];

int rec(int i,int k){
    if(i<0){
        if(k==0) return 0;
        else return -INF;
    }
    if(done[i][k]) return dp[i][k];
    int ans = rec(i-1,k);
    for(int j=1;j<=i+1;j++){//if we are at i==0 we can take 1 element that is why
        ans = max(ans,rec(rec(i-j,k-1)+p[i]-p[i-j]))
    }
    done[i][k]=1;
    return dp[i][k]=ans;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        if(i==0) cin>>arr[i];
        else{
            cin>>p[i];
            p[i]=p[i]+p[i-1];
        }
    }
    memset(dp,-1,sizeof(dp));
    memset(done,0,sizeof(done));
    cout<<rec(n-1,k)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}

