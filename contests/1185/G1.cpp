/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second   
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define setval(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll ; 
#define int ll
using namespace std;

const int N = 3e5 + 5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const long double eps = 1e-9 ;

using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;

ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

int dp[16][16][16][4]; 

int get_dp(int p , int q , int r , int lst){
    if(!(p>0 || q > 0 || r > 0)) return 1;
    int& res = dp[p][q][r][lst];

    if(~res) return res;
    res = 0 ;
    if(lst != 0 && p) res = (res + (p * get_dp(p - 1, q , r , 0)) % mod ) % mod ;
    if(lst != 1 && q) res = (res + (q * get_dp(p, q - 1 , r , 1)) % mod ) % mod ;
    if(lst != 2 && r) res = (res + (r * get_dp(p, q , r - 1 , 2)) % mod ) % mod ;
    return res ;
}

void solve()
{
    setval(dp , -1);
    int n , T , ans = 0;
    cin >> n >> T ;
    int t[n] , g[n];
    rep(i , n) cin >> t[i] >> g[i] ;
    rep(msk , 1 << n){
        int use = 0 , cnt[3] = {} ;
        rep(i , n) if(msk >> i & 1) use += t[i] , cnt[g[i] - 1]++ ;
        if(use == T){
            ans = (ans + get_dp(cnt[0] , cnt[1] , cnt[2] , 3)) % mod ;
        }
    }
    cout << ans ;
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
