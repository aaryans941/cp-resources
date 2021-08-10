struct nodeData
{
    //Use required attributes
    int mn;

    //Default Values
    nodeData() : mn(1e9) {};
};

//init(n) => build(1 , 1 , n)
struct SegTree
{
    int N;
    vector<nodeData> st;
    vector<bool> cLazy;
    vector<nodeData> lazy;

    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.resize(4 * N + 5);
    }

    //Write reqd merge functions
    void merge(nodeData &cur, nodeData &l, nodeData &r) 
    {
        cur.mn = min(l.mn, r.mn);
    }
    
    //Handle lazy propagation appriopriately
    // this is to RANGE SET values;
    void propagate(int node, int L, int R)
    {
        if(L != R)
        {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] = lazy[node];
            lazy[node*2 + 1] = lazy[node]; 
        }
        st[node] = lazy[node];
        cLazy[node] = 0;
    }
    // A IS ZERO INDEXED.

    void build(int node, int L, int R , int a[])
    {
        if(L==R)
        {
            st[node].mn = a[L-1];
            return;
        }
        int M=(L + R)/2;
        build(node*2, L, M , a);
        build(node*2 + 1, M + 1, R , a);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    void build(int node , int L , int R)
    {
        if(L==R)
        {
            st[node] = nodeData();
            return;
        }
        int M=(L + R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    nodeData Query(int node, int L, int R, int i, int j)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return nodeData();
        if(i<=L && R<=j)
            return st[node];
        int M = (L + R)/2;
        nodeData left=Query(node*2, L, M, i, j);
        nodeData right=Query(node*2 + 1, M + 1, R, i, j);
        nodeData cur;
        merge(cur, left, right);
        return cur;
    }

    nodeData pQuery(int node, int L, int R, int pos)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(L == R)
            return st[node];
        int M = (L + R)/2;
        if(pos <= M)
            return pQuery(node*2, L, M, pos);
        else
            return pQuery(node*2 + 1, M + 1, R, pos);
    }   

    void Update(int node, int L, int R, int i, int j, int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return;
        if(i<=L && R<=j)
        {
            cLazy[node] = 1;
            lazy[node].mn = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val)
    {
        if(cLazy[node])
            propagate(node, L, R);
        if(L == R)
        {
            cLazy[node] = 1;
            lazy[node].mn = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    nodeData query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }

    nodeData query(int l, int r)
    {
        if(l > r) return nodeData();
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }

    void update(int l, int r, int val)
    {
        if(l > r) return;
        Update(1, 1, N, l, r, val);
    }
};
