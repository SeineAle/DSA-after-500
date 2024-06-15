#define ceil(n, m) (((n) + (m) - 1) / (m)) 
#define ll long long
class Solution {
public:
    ll gcd(ll a,ll b){ 
        if (b==0) return a; 
        return gcd(b, a%b); 
    }
    ll lcm(ll a,ll b){ 
        return (a/gcd(a,b))*b; 
    }
    ll solve(ll n , ll a, ll b, ll c){
        ll lab = lcm(max(a, b), min(a, b));
        ll lbc = lcm(max(c, b), min(c, b));
        ll lac = lcm(max(a, c), min(a, c));
        ll labc = lcm(max(lab, c), min(lab, c));

        ll s = 0;
        ll e = n*a;

        while(s <= e){
            ll m = (s+e)/2;
            ll cost = m/a + m/b + m/c + m/labc - m/lab - m/lbc - m/lac;
            if(cost == n && (m&a == 0 || m%b == 0 || m%c == 0)) return m;
            if(cost >= n) e = m-1;
            if(cost < n) s = m+1;
        }
        return -1;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll x = solve(n, a, b, c);
        cout << x << endl;
        if(x != -1) return x;
        ll y = solve(n, b, a, c);
        cout << y << endl;
        if(y != -1) return y;
        ll z = solve(n, c, a, b);
        cout << z << endl;
        if(z != -1) return z;
        return -1;
    }
};