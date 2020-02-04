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

#define int ll

using namespace std;

const int N = 5e5 +5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;
using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef vector<int> vi;
typedef pair<int, int> pii; 
typedef pair<int , pii> piii ; 
typedef unsigned long long ull ;

int t[8 * N];
int a[N] ;
void build(int l , int r, int id){
    if(l == r){
        t[id] = a[l]; 
        return ;
    }
    int m = ( l + r ) >> 1 ;
    build(l , m , id * 2) ;
    build(m + 1, r , id * 2 + 1) ;
    t[id] = gcd(t[id*2] , t[id * 2 + 1]);
}

void upd(int l , int r , int pos , int val , int id){
    if(l == r && r == pos){
        t[id] = val ;
        return ;
    }
    int m = (l + r) >> 1; 
    if(pos <= m) upd(l , m , pos , val , id * 2) ;
    else upd(m + 1 , r , pos , val , id * 2 + 1) ;
    t[id] = gcd(t[id * 2] , t[id * 2  + 1]) ;
}

pii Lrang(int myl , int myr, int l , int x, int id){
    // cout << myl << "  " << myr << " \n" ;
    if(l <= myl && t[id] % x == 0) return {myl , myr} ;
    if(myr < l) return {-1 , -1} ;
    if(myl == myr) return (t[id] % x ? mp(-1LL, -1LL) : mp(myl , myr));
    // else if(r == myr && t[id] % x) return -1 ;
    int m = (myl + myr) >> 1;
    pii x1 = Lrang(myl , m , l , x, id * 2);
    pii x2 = Lrang(m+1 , myr , l , x, id * 2 + 1); 
    if(x1.ss + 1 == x2.ff) return {x1.ff , x2.ss};
    else if(x1.ff != -1) return x1;
    else return x2 ;
}

pii Rrang(int myl , int myr, int r , int x, int id){
    // cout << myl << "  " << myr << " \n" ;
    if(r >= myr && t[id] % x == 0) return {myl , myr} ;
    if(myl > r) return {-1 , -1} ;
    if(myl == myr) return (t[id] % x ? mp(-1LL, -1LL) : mp(myl , myr));
    // else if(r == myr && t[id] % x) return -1 ;
    int m = (myl + myr) >> 1;
    pii x1 = Rrang(myl , m , r , x, id * 2);
    pii x2 = Rrang(m+1 , myr , r , x, id * 2 + 1); 
    if(x1.ss + 1 == x2.ff) return {x1.ff , x2.ss};
    else if(x2.ff != -1) return x2;
    else return x1 ;
}

void solve()
{
    int n;
    cin >> n;
    rep(i , n) cin >> a[i + 1] ;
    build(1 , n,  1); 
    int q;
    cin >> q ;
    while(q--){
        int t;
        cin >> t ;
        if(t == 2){
            int i , y ;
            cin >> i >> y ;
            a[i] = y;
            // cout << "A[" << i << "] =" << y << '\n' ; 
            upd(1 , n , i , y , 1) ;
            continue ;
        }
        int l , r , x;
        cin >> l >> r >> x;
        // int LRang = 1 ;
        // int L = l , R = r + 1 ;
        // while(R - L > 1){
        //     int m = (L + R) >> 1;
        //     if(rang(1 , n , l , m , 1) % x == 0) L = m ;
        //     else R = m ; 
        // }
        pii LEFT = {l-1 , l-1} , RIGHT = {r + 1 , r + 1} ;
        if(a[l] % x != 0) 
            LEFT = {l - 1 , l - 1}; 
        else LEFT = Lrang(1, n, l, x, 1) ;
        // L = l , R = r + 1 ;
        // while(R - L > 1){
        //     int m = (L + R) >> 1;
        //     if(rang(1 , n , m , r , 1) % x == 0) R = m ;
        //     else L = m ; 
        // }
        if(a[r] % x != 0) 
            RIGHT = {r + 1 , r + 1}; 
        else RIGHT = Rrang(1, n, r, x, 1) ;
        // cout << LEFT.ff << " " << LEFT.ss << '\n';
        // cout << RIGHT.ff << " " << RIGHT.ss << '\n';
 
        if(RIGHT.ff - LEFT.ss <= 2){
            cout << "YES\n";
        }else cout << "NO\n"; ;
        
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