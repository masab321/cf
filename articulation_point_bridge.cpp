#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

/* 1 - based index, get_point(), get_bridges(), only pass a adjacency list in constructor;
 * may be correct for 0-based index;
 * code modified from CP3 book;
 * warning: most return types and parameters are copied.
 */
class articulation{ 
public:
    vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
    int dfs_number_counter, root, root_children, n;
    vector<vector<int>> graph;
    vector<pair<int, int>> articulation_bridge;

    articulation(vector<vector<int>> G){
        n = G.size();
        graph = G;
        dfs_num.assign(n, 0);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        articulation_vertex.assign(n, 0);
        dfs_number_counter = 0;
        driver();
    }
    void driver(){
        for(int i = 0; i < n; i++){
            if(dfs_num[i] == 0){
                root = i; root_children = 0;
                articulation_point_bridge(i);
                articulation_vertex[root] = (root_children > 1);
            }
        }
    }
    void articulation_point_bridge(int u){
        dfs_low[u] = dfs_num[u] = dfs_number_counter++;
        for(int v: graph[u]){
            if(dfs_num[v] == 0){
                dfs_parent[v] = u;
                if(u == root) root_children++;
                
                articulation_point_bridge(v);

                if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;
                if(dfs_low[v] > dfs_num[u]) articulation_bridge.push_back({u, v});
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }else if(v != dfs_parent[u]){
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }
    vector<int> get_points(){
        vector<int> ret;
        for(int i = 0; i < n; i++) if(articulation_vertex[i]) ret.push_back(i);
        return ret;
    }
    vector<pair<int, int>> get_bridges(){
        return articulation_bridge;
    }
    void show(){
        cout << "dfs_low" << endl;
        for(int i = 1; i < n; i++) cout << dfs_low[i] << " "; cout << endl;
        cout << "dfs_num" << endl;
        for(int i = 1; i < n; i++) cout << dfs_num[i] << " "; cout << endl;
        cout << "dfs_parent" << endl;
        for(int i = 1; i < n; i++) cout << dfs_parent[i] << " "; cout << endl;
    } 
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
}





