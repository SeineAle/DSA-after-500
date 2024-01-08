#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll, int>> v(n);
        int ans = 0;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                ll d = 1LL*nums[i] - nums[j];
                ll sum = 0;
                if(v[j].find(d) != v[j].end()){
                    sum = v[j][d];
                }
                v[i][d] += 1 + sum;
                ans += sum;
            }
        }
        return ans;
    }
};