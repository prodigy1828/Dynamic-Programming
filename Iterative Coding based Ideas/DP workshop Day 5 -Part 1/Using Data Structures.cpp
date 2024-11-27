#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 1E9+7;

int n,k;
int arr[1001];
int dp[1001];

struct monotone_deque{ //all the functions are O(1) - armourtized cost
    deque<int>dq;
    void insert(int x){
        while(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
        dq.push_back();
    }
    void erase(int x){
        if(dq.front()==x)dq.pop_front(); 
    }
    int getmin(){
        return dq.front();
    }
};

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    monotone_deque mt;
    dp[0] = arr[0];
    mt.inset(dp[0]);
    for(int i=1;i<n;i++){
        if(i-k-1>=0) mt.erase(dp[i-k-1]);
        dp[i] = mt.getmin()+arr[i];
        mt.insert(dp[i]);
    }
    cout<<dp[n-1]<<endl;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    //int tc;cin>>tc;while(tc--)
    solve();
    return 0;
}








