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
const int M = 5005 ;
vector<int> sufcnt[M];
int dp[M] , a , b ;

vector<int> lcp(string &s){
    int n = s.length() ;
    vector<int> pi(n , 0);
    for(int i = 1 ; i < n ; ++i){
        int j = pi[i-1] ;
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1] ;
        if(s[i] == s[j])
            j++ ;
        pi[i] = j ;
    }
    return pi ;
}


vector<int> check(string s , int k){
    int n = s.length();
    vector<int> pi = lcp(s);
    vector<int> ans(k + 1 , 0);
    for (int i = k ; i < n; i++)
        ans[pi[i]]++;
    for (int i = k-1; i > 0; i--)
        ans[pi[i-1]] += ans[i];
    return ans ;
}
void solve()
{
    int n ; // , a , b ;
    cin >> n >> a >> b ;
    string s;
    cin >> s;
    string rs(s.begin() , s.end());
    rep(i , n + 5) dp[i] = inf ;
    dp[0] = 0;
    for(int r = 0 ; r < n ; ++r){
        // s[r .. n] + '#' + s[1 .. r - 1] 
        dp[r + 1] = min(dp[r + 1] , dp[r] + a);
        if(r == 0 /*|| r == n - 1*/) continue ;
        string use1(s.begin() , s.begin() + r);
        string use2(s.begin() + r  , s.end());
        string use = use2 + '#' + use1;
        auto here_pfx_count = check(use , n - r);
        for(int i = 1 ; i <= n - r ; ++i){
            if( here_pfx_count[i] >= 1 ){
                dp[i + r] = min(dp[r + i] , dp[r] + b);
            }
        }
    }

    cout << dp[n] << '\n' ;
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
