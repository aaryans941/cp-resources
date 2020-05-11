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
#define rall(c) (c).rbegin(),(c).end()
#define setval(a,val) memset(a,val,sizeof(a))
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

typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;

ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

void solve()
{
    int n , k , a , b; 
    cin >> n >> k >> a >> b ;
    char put[2] = {'G' , 'B'}; 
    if(a > b) swap(a , b) , swap(put[0] , put[1]); 
    string ans = "" ;
    if(k == 1){
        if( b - a > 1 ) {
                cout << "NO";
                return;
        }
        else{
            rep(i , n) ans += put[1-(i%2)];
            cout << ans ;
            return ;
        }
    }
    int mil = (a + k - 1) / k , mxl = a ; // a + k - 1) / k ;
    int blocks = (b + k - 1) / k ;
    if(blocks - 1 > a){
            cout << "NO";
            return;
    }
    if(blocks == mxl){
        while(a || b){
            rep(i , min(b , k)) ans += put[1];
            rep(i , min(a , k)) ans += put[0];
            b -= min(b , k) , a -= min(a , k);
        }
    }else{
       rep(i , min(k , b)) ans += put[1] ;
       b -= min(b , k);
       while(a > 0 || b > 0){
            int use_a = min(a , k);
            use_a = min(use_a , a-(b-1)/k);
            a -= use_a ;
            rep(i , use_a) ans += put[0];
            rep(i , min(b , k)) ans += put[1];
            b -= min(b , k);
       }
    }
    cout << ans ;

}   

     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}
