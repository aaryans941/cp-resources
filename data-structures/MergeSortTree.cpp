const int M = 1e5 + 5; 
vi t[4 * N], A[N];

#define m ((l + r)/2)

//A is zero indexed, and is sorted
void build(int l , int r, int id){
    if(l == r){
        trav(x , A[l-1]) t[id].pb(x);
        return;
    }
    build(l , m, id * 2);
    build(m+1, r, id*2 + 1);
    t[id].resize(sz(t[id*2] + sz(t[id*2+1])));
    merge(all(t[id*2]),all(t[id*2+1]),t[id].begin());
}

// how many numbers >= Qx in [Ql , Qr]
int query(int l , int r, int Ql , int Qr, int Qx, int id){
    if(l > Qr || r < Ql) return 0;
    if(Ql <= l && r <= Qr){
        return upper_bound(all(t[id]) , Qx) - t[id].begin();
    }
    return (query(l,m,Ql,Qr,Qx,2*id) + query(m+1,r,Ql,Qr,Qx,id*2+1));
}



