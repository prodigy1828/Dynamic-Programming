#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
int arr[505];
int dp[505][505];

int rec(int l,int r){
    if(l==r) return 0;//single element cannot be merged
    if(dp[l][r]!=-1) return dp[l][r];
    int ans = 0 ;
    int tot = 0 ; 
    int sum = 0 ;
    for(int mid=l;mid<=r;mid++){
        tot+=arr[mid];//here we store the total sum in the interval [L,R]
    }
    for(int mid=l;mid<r;mid++){//we only iterate till mid-1 because othewise it passes through and violates our base case
        sum+=arr[mid];// here we are storing the left interval value from [L,mid]
        ans = max(ans,rec(l,mid)+rec(mid+1,r)+(sum%100)*((tot-sum)%100));
    }
    return dp[l][r]=ans;
}

void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
