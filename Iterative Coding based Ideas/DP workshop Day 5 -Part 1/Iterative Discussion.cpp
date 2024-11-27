#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,s;
int arr[1001];
int dp[1001][1001];

int rec(int i,int sum_left){
    if(sum_left<0) return 0;
    if(i==n){
        if(sum_left==0){
            return 1
        }else {
            return 0;
        }
    }
    if(dp[i][sum_left]!=-1) return dp[i][sum_left];
    int ans = rec(i+1,sum_left);
    for(int x=1;x<=arr[i];x++){
        ans += rec(i+1,sum_left-x);
    }
    return dp[i][sum_left] = ans;
}

void solve(){
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=n;i>=0;i--){
        for(int sum_left=0;sum_left<=s;sum_left--){
            if(i==n){
                if(sum_left==0){
                dp[i][sum_left] = 1;
            }else {
               dp[i][sum_left]=0;
                }
                continue;
            }
            int ans = 0;
            for(int x=0;x<=arr[i];x++){
                if(sum_left>=x) ans += dp[i+1][sum_left-x]; 
            }
            dp[i][sum_left] = ans;
        }
    }
    
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    //int tc;cin>>tc;while(tc--)
    solve();
    return 0;
}








