#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF =  1e9;

int n ;
string s;
int dp1[1001][1001];
int dp2[1001];

void solve(){
    cin>>s;
    n = s.length();
    for(int len=1;len<=n;len++){
        for(int l=0;l+len-1<n;l++){ //this gives us the end point for every start for a given lenght(Form 4 iterative template)
            int r = len+l-1;//end point
            if((r-l+1)==1) dp1[l][r]=1;//when only single string is present it is always palindrome
            else if((r-l+1)==2) dp1[l][r] = (s[l] == s[r]);//when lenght is 2 just check the two elememts of the string
            else dp1[l][r] =  (dp1[l+1][r-1] && s[l]==s[r]);
        }
    }
    
    for(int i=0;i<n;i++){//these all states are to be computed
        dp2[i]=INF;
        for(int j=i;j>=0;j--){
            if(dp1[j][i]){
                if(j==0) dp2[i]=min(dp2[i],1LL);
                else dp2[i]=min(dp2[i],1+dp2[j-1]);
            }
        }
    }
    cout<<dp2[n-1]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
