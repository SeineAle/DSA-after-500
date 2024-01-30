class Solution {
public:
    vector<vector<int>> subarrayCost;
    vector<vector<int>> dp;
    int cost;
    int solve(int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k <= j; k ++){
            ans = min(ans, cost + solve(k + 1, j) + subarrayCost[i][k]);
        }
        return dp[i][j] = ans;
    }
    int minCost(vector<int>& nums, int k) {
        this->cost = k;
        int n = nums.size();
        subarrayCost.resize(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++){
            map<int, int> mp;
            for(int j = i; j < n; j ++){
                mp[nums[j]] ++;
                if(i == j)continue;
                subarrayCost[i][j] = subarrayCost[i][j-1];
                if(mp[nums[j]] == 2) subarrayCost[i][j] += 2;
                else if(mp[nums[j]] > 2) subarrayCost[i][j] += 1;
            }
        }
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n-1);
    }
};