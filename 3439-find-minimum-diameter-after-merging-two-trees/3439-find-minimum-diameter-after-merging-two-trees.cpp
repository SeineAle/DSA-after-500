#include <bits/stdc++.h>

using namespace std;
// TYPE DEF
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define ll long long
#define ull unsigned long long
#define db double

// REPLACEMENTS
#define pb push_back

#define fi first
#define se second

#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define pll pair<long long, long long>
#define vll vector<long long>
class Solution {
public:
    void setAlpha(ll curr, ll par, vector<pll> & alpha, vector<vll> & tree){
      ll a = 0, b = -1;
      for(auto next : tree[curr]){
        if(next == par) continue;
        setAlpha(next, curr, alpha, tree);
        ll c = alpha[next].fi + 1;
        if(c > a){
          b = a;
          a = c;
        }
        else if(c > b){
          b = c;
        }
      }
      alpha[curr] = {a, b};
    }
    void setAns(ll curr, ll par, vector<pll> & alpha, vector<vll> & tree, ll& x, ll& y){
      ll a = alpha[curr].fi, b = alpha[curr].se;
      ll a_ = a, b_ = b;
      ll c = alpha[par].fi;
      if(a + 1 == alpha[par].fi){
        c = alpha[par].se;
      }
      c += 1;
      if(c > a){
        b = a;
        a = c;
      }
      else if(c > b){
        b = c;
      }
      x = min(x, a);
      y = max(y, a);
      alpha[curr] = {a, b};
      for(auto next : tree[curr]){
        if(next == par) continue;
        setAns(next, curr, alpha, tree, x, y);
      }
      alpha[curr] = {a_, b_};  
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<ll>> tree1(edges1.size() + 1);
        vector<vector<ll>> tree2(edges2.size() + 1);
        for(auto e : edges1){
            ll u = e[0];
            ll v = e[1];
            tree1[u].pb(v);
            tree1[v].pb(u);
        }
        for(auto e : edges2){
            ll u = e[0];
            ll v = e[1];
            tree2[u].pb(v);
            tree2[v].pb(u);
        }
        vector<pll> a(tree1.size()), b(tree2.size());
        setAlpha(0, -1, a, tree1);
        setAlpha(0, -1, b, tree2);
        ll ans = LLONG_MIN;
        for(auto p : a){
            ans = max(ans, p.fi);
        }
        for(auto p : b){
            ans = max(ans, p.fi);
        }
        ll w = a[0].fi;
        ll x = a[0].fi;
        ll y = b[0].fi;
        ll z = b[0].fi;
        for(auto next : tree1[0]){
            setAns(next, 0, a, tree1, w, x);
        }
        for(auto next : tree2[0]){
            setAns(next, 0, b, tree2, y, z);
        }
        return max(max(x, z), w+y+1);
    }
};