#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
pair<double,double>p[101];
int dp[1001][1001];

double sq(double x){
    return x*x;
}

double cost(int x,int y){
    double dist = sqrt(sq(p[x].first-p[y].first)+sq(p[x].second-p[y].second));
    return sin(dist);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
    }
    double dp[n+1][n+1];
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1;l++){
            int r=l+len-1;
            //dp[l][r]
            if(len==3){//already a triangle
                return 0 ;
            }
            //compute
            double ans = 1e9;
            for(int x=l+1;x<=r-1;x++){
                    if(x==l+1){
                        ans = min(ans,cost(l+1,r)+dp[l+1][r]);
                    }else if(x==r-1){
                        ans = min(ans,cost(l,r-1)+dp[l][r-1]);
                    }else{
                        ans = min(ans,cost(l,x)+cost(x,r)+dp[l][x]+dp[x][r]);
                    }
                }
                dp[l][r]=ans;
            }
        }
        cout<<dp[1][n]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}

