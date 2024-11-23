#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1E9;

int n,m;
int arr[1001];

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int dp[n+1][m+1];//ensure that the base cases also have the memory allocation as in recursion they we not required to be stored
    for(int l=n;l>=0;l--){
        for(int s=0;s<=m;s++){
            //compute  for (l,s)
            if(l==n){
                if(s==0){
                    dp[l][s]=1;
                }else{
                    dp[l][s]=0;
                }
            }
            //general
            dp[l][s] = 0 ;
            if(l<n && dp[l+1][s]){
                dp[l][s] = 1;
            }
            if(s>=arr[l] && dp[l][s-arr[l]]){
                dp[l][s] = 1;                
            }
        }
    }
    cout<<dp[0][m]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}





