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

// VAR
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
vector<string> ret = {"NO", "YES"};

// REPLACEMENTS
#define pb push_back

#define fi first
#define se second

#define f(i, n) for(ll i = 0; i < n; i ++)
#define f1(i, n) for(ll i = 1; i <= n; i ++)
#define f_(i, n) for(ll i = n-1; i >= 0; i --)

#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define mll map<long long, long long>
#define si set<int>
#define sc set<char>
#define pq(t) priority_queue<t>
#define rpq(t) priority_queue<t, vector<t>, greater<t>>

#define sz(x) (long long)(x.size())

#define out(A) {for(auto a : A)cout << a << " "; cout << endl;}
#define in(A) {f(i, sz(A))cin >> A[i];}

// MODULO ARITHMATICS
#define ceil(n, m) (((n) + (m) - 1) / (m)) 
#define addm(a, b, m) (((a % m) + (b % m)) % m)
#define subm(a, b, m) (((a % m) - (b % m) + m) % m)
#define mulm(a, b, m) (((a % m) * (b % m)) % m)

// FUNCTIONS

ll binpow(ll b, ll e, ll mod = LLONG_MAX) {
    ll r = 1;
    b %= mod;
    while (e > 0) {
        if (e & 1) {
            r = mulm(r, b, mod);
        }
        e >>= 1;
        b = mulm(b, b, mod);
    }
    return r;
}

ll gcd(ll a,ll b){ 
    if (b==0) return a; 
    return gcd(b, a%b); 
}

ll lcm(ll a,ll b){ 
    return (a/gcd(a,b))*b; 
}

bool isPrime(ll n) {
    if (n <= 1) {
        return false;
    }
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool pal(ll n){
    ll r = 0;
    ll tmp = n;
    while(tmp != 0){
        r = r*10+tmp%10;
        tmp /=10;
    }
    return r==n;
}

vector<ll> factors(ll n) {
    vector<ll> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

ll gcdExtended(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll gcd = gcdExtended(a, m, x, y);
    if (gcd != 1) return -1;
    ll result = (x % m + m) % m;
    return result;
}

vector<string> split(string & s, char b, bool empty = false){
    stringstream ss(s);
    vector<string> tokens; string token;
    while(getline(ss, token, b)){
        if(!empty && !token.size()) continue;
        tokens.push_back(token);
    }
    return tokens;
}

void factorials(vll & fact_, ll n, ll m = MOD){
    fact_.push_back(1);
    f1(i, n) fact_.push_back(mulm(fact_.back(), i, m));
}

vector<vll> dir = {{0,0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

/***********************************************/

// void solve(){
//   cin >> n >> k >> m;
//   vector<vll> tree(n);
//   f(i, n-1){
//     ll u, v; cin >> u >> v; u --; v --;
//     tree[u].pb(v);
//     tree[v].pb(u);
//   }
//   vector<pll> alpha(n);
//   setAlpha(0, -1, alpha, tree);
//   ans = alpha[0].fi * k;
//   for(auto next : tree[0]){
//     setAns(next, 0, alpha, tree, 1);
//   }
//   cout << ans << endl;
// }
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
        cout << a.size() << endl;
        for(auto p : a){
            cout << p.fi << " " << p.se << endl;
        }
        cout << b.size() << endl;
        for(auto p : b){
            cout << p.fi << " " << p.se << endl;
        }
        cout << x << " " << y << endl;
        for(auto next : tree1[0]){
            setAns(next, 0, a, tree1, w, x);
        }
        for(auto next : tree2[0]){
            setAns(next, 0, b, tree2, y, z);
        }
        cout << x << " " << y << endl;
        vll temp = {w, x, y, z};
        out(temp);
        return max(max(x, z), w+y+1);
    }
};