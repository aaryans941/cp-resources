const int M = 5e5 + 5; 
ll BIT[M];

void upd(ll BIT[] , int pos , ll val){
    assert(pos>0);
    for(;pos<M;pos+=pos&-pos)
        BIT[pos]+= val ;
}

ll psum(ll BIT[], int pos){
    ll res = 0;
    for(;pos>0;pos^=pos&-pos)
        res+=BIT[pos];
    return res;
}

ll rsum(ll BIT[] , int l , int r){
    if(l > r) return 0;
    return psum(BIT, r) - psum(BIT , l-1);
}
