/**
 * author: masab hasnain
 * Time: 2021-02-16 21:24:42
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
class seg_tree{ //1 based indexed. first item should be at position 1;
private:
    int n;
    vector<int> tree;
    vector<int> in;
public:
    seg_tree(vector<int> _in, int sz){
        tree.assign((sz + 5) * 4 + 10, 0);
        n = sz;
        in = _in;
        build(1, 1, sz);
    }
    void build(int v, int l, int r){
        if(l == r){
            tree[v] = l;
        }else{
            int mid = l + r; mid >>= 1;
            build(v * 2, l, mid);
            build(v * 2 + 1, mid + 1, r);
            if(in[tree[v * 2]] > in[tree[v * 2 + 1]]) tree[v] = tree[v * 2];
            else tree[v] = tree[v * 2 + 1];
        }
    }
    int query(int v, int l, int r, int tl, int tr){
        if(tr < l or tl > r) return -1;
        if(tl >= l and tr <= r) return tree[v];
        
        int mid = tl + tr; mid >>= 1;
        int left = query(v * 2, l, r, tl, mid);
        int right = query(v * 2 + 1, l, r, mid + 1, tr);
        
        if(left == -1) return right;
        if(right == -1) return left;

        if(in[left] > in[right]) return left;
        else return right;
    }
    void update(int val, int v, int pos, int l, int r){
        int mid = l + r; mid /= 2;
        if(mid == pos){
            tree[v] = val;
            in[pos] = val;
            return;
        }
        if(mid > pos) update(val, v * 2, pos, l, mid);
        if(mid < pos) update(val, v * 2 + 1, pos, mid + 1, r);

        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
    int query(int l, int r){
        return query(1, l, r, 1, n);
    }
    void update(int pos, int val){
        update(val, 1, pos, 1, n);
    }
};

void recur(vector<int> &in, int n, seg_tree &sg, int l, int r, vector<vector<int>> &tr){
    int parent = sg.query(l, r);
    int left = -1, right = -1;
    if(parent > l){
        left = sg.query(l, parent - 1);
    }
    if(parent < r){
        right = sg.query(parent + 1, r);
    }
    if(left != -1){
        tr[in[parent]].push_back(in[left]);
        recur(in, n, sg, l, parent - 1, tr);
    }
    if(right != -1){
        tr[in[parent]].push_back(in[right]);
        recur(in, n, sg, parent + 1, r, tr);
    }
}
void dfs(vector<int> &res, int v,int level, vector<vector<int>> &tr){
    res[v] = level;
    for(int i: tr[v]) dfs(res, i, level + 1, tr);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> in(n + 1);
        for(int i = 1; i <= n; i++) cin >> in[i];
        seg_tree sg(in, in.size());
        vector<vector<int>> tr(n + 5);
        recur(in, n, sg, 1, n, tr);
        
        vector<int> res(n + 5, 0);
        dfs(res, n, 0, tr);
        for(int i = 1; i <= n; i++){
            cout << res[in[i]] << " ";
        }
        cout << endl;

    }

}




