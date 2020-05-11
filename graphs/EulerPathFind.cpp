
/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define popb pop_back
#define mt make_tuple 
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second   
#define beg begin
#define rep(i,n) for(int (i) = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define fill(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll ; 
typedef long double ld ; 

#define int ll

using namespace std;

const int N = 3e5 +5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;
using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef vector<int> vi;
typedef pair<int, int> pii; 
typedef vector<pii> vpii;
typedef pair<int , pii> piii ; 
typedef unsigned long long ull ;


void solve()
{
    int n , m ;
    cin >> n >> m ; 
    vector<int> adj[n + 1];
    for(int i = 0 ; i < m ; ++i){
        int x , y ;
        cin >> x >> y; 
        adj[x].pb(y);
        adj[y].pb(x); 
    }
    int lst = 1, cnt = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        if(sz(adj[i]) & 1) cnt++ , lst = i ; 
    }
    if(cnt != 0 && cnt != 2){
        cout << "LMAO NO\n"; // add action;
        return ; 
    }
    vector<int> answer ;
    stack<int> st;
    st.push(lst);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(adj[u].empty()) answer.pb(u);
        else{
            st.push(adj[u].back());
            adj[u].pop_back();
        }
    }

    for(int i = 1; i <= n ; ++i) if(!adj[i].empty()){
        cout << "LMAO NO(1)\n"; // add action
        return; 
    }
    trav(x , answer) cout << x << ' ' ;
}   

     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    //cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}
