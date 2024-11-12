#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int getBestSubarray(vector<int>&arr){
    int n = arr.size();
    int run = arr[0];
    int ans = arr[0];
    for(int i=1;i<n;i++){
        run = max(arr[i],run+arr[i]);
        ans = max(ans,run);
    }
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    //m<n (WLOG)
    int ans = -1e9 ;
    if(m<n){
        for(int c1=0;c1<m;c1++){
            vector<int>rowSum(n,0);
            for(int c2=c1;c2<m;c2++){
                for(int r=0;r<n;r++){
                    rowSum[r]+=arr[r][c2];
                }
                ans = max(ans,getBestSubarray(rowSum));
            }
        }
    }else{
        for(int r1=0;r1<n;r1++){
            vector<int>colSum(m,0);
            for(int r2=r1;r2<n;r2++){
                for(int c=0;c<m;c++){
                    colSum[c]+=arr[r2][c];
                }
                ans = max(ans,getBestSubarray(colSum));
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc;cin>>tc;while(tc--)
    solve();
}





