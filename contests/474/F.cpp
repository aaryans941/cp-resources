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

const int N = 1e5 + 5 ;
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

pii t[4 * N] ;
int a[N] ;


pii combine(pii a , pii b){
    int g = gcd(a.ff , b.ff);
    int c = (g == a.ff ? a.ss : 0) + (g == b.ff ? b.ss : 0);
    return mp(g , c); 
}

void build(int l , int r , int id){
    if(l == r){
        t[id] = mp(a[l] , 1LL);
        return ;
    }
    int m = l + (r - l) / 2;
    build(l , m , id * 2);
    build(m + 1, r , id * 2 + 1);
    // int g = gcd(t[id * 2].ff , t[id * 2 + 1].ff);
    // int c = (g == t[id * 2].ff ? t[id * 2].ss : 0) + (g == t[id * 2 + 1].ff ? t[id * 2 + 1].ss : 0) 
    t[id] = combine(t[id * 2] , t[id * 2 + 1]);
}

pii query(int l , int r, int Ql , int Qr, int id){
    if(l > Qr || r < Ql) return mp(0 , 0) ;
    if(Ql <= l && r <= Qr) return t[id];
    int m = l + (r - l) / 2; 
    return combine(query(l , m , Ql , Qr , id * 2) , query(m + 1 , r , Ql , Qr , id * 2 + 1));
}




void solve()
{
    int n ;
    cin >> n;
    rep(i , n) cin >> a[i + 1] ;
    int q;
    cin >> q;
    build(1 , n , 1);

    rep(_ , q){
        int l , r ;
        cin >> l >> r; 
        pii gc = query(1 , n , l , r , 1);
        // Q[i].g = gc ;
        cout << (r - l + 1 - gc.ss) << '\n';
    }
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
