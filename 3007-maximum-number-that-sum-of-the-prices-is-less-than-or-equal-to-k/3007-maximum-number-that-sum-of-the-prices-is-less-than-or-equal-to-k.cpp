typedef long long int64;
#define ll long long 
class Solution {
public:
    ll findCost(ll m, int x){
        ll n = 0;
        ll m_ = m;
        while(m_){
            n ++;
            m_ = m_ >> 1;
        }
        m ++;
        ll sol = 0;
        for(ll i = x; i <= n; i += x){
            ll p = 1LL << i; 
            sol += (p/2)*(m/p) + max((m%p) - (p/2),  0LL);
        }
        return sol;
    }
    ll findMaximumNumber(long long k, int x) {
        ll l = 1; ll r = 1e15;
        ll ans;
        while(l <= r){
            ll m = (l+r) >> 1;
            ll cost = findCost(m, x);
            if(cost <= k){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return r;
    }
};