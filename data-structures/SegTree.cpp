const int SEGTREE_SIZE = 3e5 + 5; 
node{
    int val; 
    node(int b){
        val = b; 
    }
    bool operator<(const node& r){
        return val < r.val ;
    }

    node operator+(const node& r){
        return node(val + r.val); 
    }
}; 


template <typename T>
struct SegTree{
    vector<T> st; 
    vector<bool> clazy;
    vector<T> lazy; 

    void init(int n){
        st.assign(4*n + 5); 
        clazy.resize(4*n + 5);
        lazy.assign(4*n + 5);
    }

    void merge(T &cur,  T a , T b){
        cur = (a < b ? a : b) ;
    }

    void UpdMerge(T& l1 , T l2){
        l1  = l2 ;
    }
    void propagate(int id , int L , int R){
         if(!clazy[id]) return; 
         if(L != R){
           clazy[id * 2] = clazy[id * 2 + 1]; 
           UpdMerge(lazy[id * 2], lazy[id]); 
           UpdMerge(lazy[id * 2 + 1], lazy[id]); 
        }
        UpdMerge(st[id] , lazy[id]); 
        clazy[id] = 0; 
    }
    void build(int L , int R , int id){
        if(L == R){
            st[id] = node(); 
            return ; 
        }
        int M = (L + R) >> 1;
        build(L , M , id * 2); 
        build(M+1, R , id * 2 + 1); 
        merge(st[id] , st[id * 2] , st[id * 2 + 1]); 
    }

    
    void build(int L , int R , int id , T a[]){
        if(L == R){
            st[id] = a[L-1] ;
            return; 
        }
        int M = (L + R) >> 1;
        build(L , M , id * 2 , a); 
        build(M+1, R , id * 2 + 1 , a); 
        merge(st[id] , st[id * 2] , st[id * 2 + 1]); 
    }

    void pUpdate(int L , int R , int id , int pos , T val){
        if(clazy[id])
            propagate(id , L , R);
        if(L == R){
            lzy[id] = val; 
            clazy[id] = true;
            propagate(id , L , R);
            return;
        }
        int M = (L + R) >> 1; 
        if(pos <= M){
            pUpdate(L , M , id * 2 , pos , val); 
        }else pUdate(M + 1, R, id * 2 + 1, pos , val);
        merge(st[id] , st[id * 2] , st[id * 2 + 1]);
    }
    
    void Update(int L , int R , int id , int QL , int QR , int QX){
        if(clazy[id])
            propagate(
        if(L > QR || R < QL) return ;
        if(QL <= L && R <= QR){
            clazy[id] = true; 
            UpdMerge(lzy[id] , QX); 
        }
    }

}
