#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF =  1e9;

int n ;
string s;

int dp1[1001][1001];

int rec1(int l,int r){//palindrome check recursion (O(N^2)).
    //pruning 
    //base case
    if((r-l+1)==0||(r-l+1)==1) return 1; //if the length of string is 0 or one that string is palindrome
    //cache check
    if(dp1[l][r]!=-1) return dp1[l][r];
    //compute
    int ans = (rec1(l+1,r-1) && s[l]==s[r]);
    //save and return
    return dp1[l][r] = ans;
}

int dp2[1001];
int rec2(int i){
    //pruning 
    //base case
    if(i==-1) {
        return 0;//whole string is cut
    }
    //cache check
    if(dp2[i]!=-1){
        return dp2[i];
    }
    //compute
    int ans  = INF;
    for(int j=i;j>=0;j--){
        if(rec1(j,i)){
            ans  = min(ans,1+rec2(j-1));
        }
    }
    //save and return
    return dp2[i] = ans;
}

void solve(){
    cin>>s;
    n = s.length();
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<rec2(n-1)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
