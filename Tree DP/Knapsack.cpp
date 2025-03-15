#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pair<int,int>>>
#define vvvi vector<vector<vector<int>>>
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define inp(v) for(auto& x : v) cin >> x;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >=b; i--)
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define rz resize
#define as assign
const int MOD = 1E9+7;
const int INF = 1E18;
 
template<typename T, typename U>
T& amax(T&x, U y) {if(y > x) x = y; return x;}
template<typename T, typename U>
T& amin(T&x, U y) {if(y < x) x = y; return x;}

int n,k;
vi g[101];
int arr[101];//value at all nodes
int sz[101];//subtreesz of all nodes
int dp[101][2][101]; //(nodes,flag,child left to be taken)

void dfs(int node,int par){
    rep(i,0,k+1){
        //this is the base case for the leaf node where if the we are at it and we have to take it then 
        //answer is only possible only when only one node is left to be processed rest all are invalid
        dp[node][1][i] = (i==1 ? arr[node] : -INF);
        //similarly when we are at leaf and we do not have to take it the only valid state is one where 
        //all nodes are procesed
        dp[node][0][i] = (i==0 ? 0 : -INF);
    }
    for(auto v : g[node]){
        //first do dfs over all the child
        dfs(v,node);
        //now we loop from the back and update every node child combionation
        //it is kind of implemeting dp2 array in dp1 itself
        rrep(a,sz[node],0){
            rrep(b,sz[v],0){
                dp[node][0][a+b] = max(dp[node][0][a+b],dp[node][0][a]+max(dp[v][0][b],dp[v][1][b]));
                dp[node][1][a+b] = max(dp[node][1][a+b],dp[node][1][a]+dp[v][0][b]);
            }
        }
        //store the subtree size of all the nodes
        sz[node]+=sz[v];
    }
}

void solve(){
    cin>>n>>k;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);
    cout<<max(dp[1][0][k],dp[1][1][k])<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}
