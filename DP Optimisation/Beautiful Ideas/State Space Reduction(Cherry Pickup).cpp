#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1E9;

int n,m;
int arr[1001][1001];
int dx[]={0,1};
int dy[]={1,0};

int check(int a,int b){
    if(a>=0 && b>=0 && a<n && b<m)return true;
    else return false;
}

int dp[101][101][101];

int rec(int i,int j,int a,int b){//max collection  to reach (n-1,m-1)
    cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
    //basecase
    if(i==n && j==m){
        return arr[i][j];
    }
    //cache check
    if(dp[i][j][a]!=-1) return dp[i][j][a];//state space reduction
    //transition 
    int initial_cost = arr[i][j]+arr[a][b]; 
    if(a==i && b==j){
        initial_cost = arr[i][j];
    }
    int ans  = 0 ;
    for(int k1=0;k1<2;k1++){
        for(int k2=0;k2<2;k2++){
            int ni,nj,na,nb;
            ni=i+dx[k1];
            nj=j+dy[k1];
            na=a+dx[k2];
            nb=b+dy[k2];
            if(check(ni,nj) && check(na,nb)){
                ans = max(ans,initial_cost+rec(ni,nj,na,nb));
            }
        }
    }
    //save and return
    return dp[i][j][a] = ans;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0,0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}





