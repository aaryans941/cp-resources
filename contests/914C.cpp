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

const int N = 3e5 +5 ;
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

// What I need = > 

int ops[1001];
int fac[1001]; 

int po (int a ,int n){
    int res = 1;
    while(n){
        if(n & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        n >>= 1; 
    }
    return res ;
}
int ncr(int n , int r){
    if(r > n || r < 0) return 0 ;
    int res = fac[n];
    res = (res * po(fac[r] , mod - 2)) % mod;
    res = (res * po(fac[n-r] , mod - 2)) % mod ;
    // cout << n << " " << r << " " ;
    // cout << res << "\n" ;
    return res ;
}
void solve()
{
    string n ;
    cin >> n ;
    int k;
    cin >> k ;
    if(k == 0){
        cout << 1; 
        return ; 
    }
    if(n == "1"){
        cout << (k == 0);
        return ;
    }
    vector<int> bruh[1001]; 
    fac[0] = 1;
    rep(i , 1001) if(i) fac[i] = (fac[i-1] * i) % mod ;
    // rep(i , 100) cout << fac[i] << ' ';
    int donebits = 0; 
    repA(i , 2, 1000){
        ops[i] = ops[__builtin_popcountll(i)] + 1; 
    }
    repA(i, 1, 1000){
        // cout << i << " " << ops[i] << "\n" ;
        bruh[ops[i]].pb(i) ;
        // bruh[i] += bruh[i-1] ;
    } 
    // trav(x , bruh[k-1]) cout << x << " " ;
    // cout << '\n' ;
    int ans = 0 ;
    int LEN = n.length(); 
    int bit[LEN] , curbits = 0; 
    rep(i , LEN){
        bit[i] = n[i] - '0'; 
        donebits++ ;    
        if(bit[i] == 0){
            continue ;
        }else{
            trav(x , bruh[k - 1]){
                if(x < curbits || x - curbits > LEN - donebits) continue ;
                // cout << curbits << " " << x << " " << LEN - donebits << "\n" ;
                ans = (ans + ncr((LEN - donebits) , x - curbits)) % mod; 
            }
            curbits++ ;
            if(i == 0 && k == 1) ans = (ans + mod - 1) % mod ;        
        }
    }
    if(ops[curbits] == k - 1) ans = (ans + 1) % mod ;
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