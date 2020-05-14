struct BIT{
    int size;
    vector<int> container;
    BIT(int N):size(N),container(N, 0) {}
    void add(int p, int x) {
        for (   ; p < size; p |= (p+1)){
            container[p] += x;
        }
    }
    int range_sum(int l, int r) {
        if (l > 0) return range_sum(0, r) - range_sum(0, l-1);
        int res = 0;
        for (   ; r >= 0; r = (r&(r+1))-1) res += container[r];
        return res;
    }
    int get_val(int p) {
        return range_sum(p, p);
    }
    void set_val(int p, int x) {
        add(p, x - get_val(p));
    }
};
