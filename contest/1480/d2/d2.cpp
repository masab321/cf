
/**
 * author: masab hasnain
 * Time: 2021-03-20 22:14:16
**/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int seg(vector<int> in){
    int ret = 0;
    for(int i = 0; i < in.size(); i++){
        int r = i + 1;
        while(r < in.size() and in[r] == in[i]) r++;
        i = r - 1;
        ret++;
    }
    return ret - 1;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> in, d[n + 5];
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        k--;
        in.push_back(k);
        d[k].push_back(i);
    }
    if(in.size() == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> a, b;
    a.push_back(-1); b.push_back(-1);
    for(int i = 0; i <= n; i++) d[i].push_back(n);
    
    for(int i = 0; i < n; i++){
        {  
            if(a.back() != in[i] and b.back() == in[i]) ;
            else if(b.back() != in[i] and a.back() == in[i]) ;
            else if(a.back() == b.back() and in[i] == a.back());
            else{
                int x, y;
                if(a.back() == -1) x = n;
                else x = *lower_bound(d[a.back()].begin(), d[a.back()].end(), i);
                

                if(b.back() == -1) y = n;
                else y = *lower_bound(d[b.back()].begin(), d[b.back()].end(), i);

                if(x > y){
                    a.push_back(in[i]);
                }else{
                    b.push_back(in[i]);
                }
            }
        }
    }

    /* cout << "IN" << endl; for(int i: in) cout << i << " "; cout << endl; */
    /* cout << "A" << endl; for (int i: a) cout << i << " "; cout << endl; */
    /* cout << "B" << endl; for (int i: b) cout << i << " "; cout << endl; */
    int res = seg(a) + seg(b);    
    cout << res << endl;
}




