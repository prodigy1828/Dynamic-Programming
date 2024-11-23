#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1E9;

int a,b;
void solve(){
    cin>>a>>b;
    for(int x=0;x<=a;x++){
        for(int y=0;y<=b;y++){
            if(x==0 && y==0) dp[0][0]=0;
            int ans = 0 ;
        for(int z=1;z<=x;z++){
            if(dp[x-z][y]==0) ans=1; 
            }
        for(int z=1;z<=y;z++){
            if(dp[x][y-z]==0) ans = 1;
            }
        for(int k=1;k<=min(x,y);k++){
            if(dp[x-k][y-k]==0) {
                ans = 1;
                break;
                }
            }
        dp[x][y]=ans;
        }
    }
    cout<<dp[a][b]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}





