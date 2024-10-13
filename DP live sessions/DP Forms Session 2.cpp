#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n,j;
int arr[101];
bool done[101][101];
int dp[101][101];

int rec(int i ,int j){//min value to break [0....i] in j parts
    //pruning 
    if((i+1<j)||j<0) return INF;//when the no of parts to be broken becomes more the no of elements left
    //basecase                or if the subparts to be broken in becomes negative
    if(i==-1){ // this reduces the amount of code to be written in compute
        if(j==0){
            return 0;
        }else{
            return INF;
        }
    }
    //cache check
    if(done[i][j]) return dp[i][j];
     //compute
    int ans = INF;
    int runmax = arr[i];
    for(int x=i;x>=0;x--){
        runmax = max(runmax,arr[x]);
        ans = min(ans,runmax + rec(x-1,j-1));
    }
    //save and return;
    done[i][j]=1;
    return dp[i][j] = ans;
}

void solve(){
    cin>>n>>j;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,j)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
