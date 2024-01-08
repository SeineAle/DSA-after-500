#define ll long long
class Solution {
public:
    ll mod = 1000000007;
    vector<vector<ll>> helper(string &s){
        int n = s.size();
        vector<vector<ll>> alpha;
        vector<ll> temp(100, 0);
        alpha.push_back(temp);
        map<int, int> mp; mp[s[0] - '0'] = 1;
        for(int i = 1; i < n; i ++){
            int x = s[i] - '0';
            alpha.push_back(alpha.back());
            for(auto y : mp){
                alpha[i][(y.first)*10 + x] = (alpha[i][(y.first)*10 + x] + y.second) % mod;
            }
            mp[x] ++;
        }
        return alpha;
    }
    int countPalindromes(string s) {
        int n = s.size();
        if(n < 5) return 0;
        vector<vector<ll>> alpha = helper(s);
        reverse(s.begin(), s.end());
        vector<vector<ll>> beta = helper(s);
        ll ans = 0;
        for(int i = 2; i < n-2; i ++){
            for(int j = 0; j < 100; j ++){
                int k = 10*(j%10) + j/10;
                ans  = (ans + (alpha[i-1][j] * beta[n-i-2][j]) % mod) % mod;
            }
        }
        return ans;
    }
};