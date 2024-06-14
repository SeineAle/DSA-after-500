class Solution {
public:
    int solve(vector<vector<int>> & freq, int i, int j, vector<vector<int>> & dp){
        if(i >= freq.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = 0; k < 10; k ++){
            if(j == k) continue;
            ans = min(ans, solve(freq, i+1, k, dp) + freq[i][k]);
        }
        return dp[i][j] = ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> freq(m, vector<int>(10, 0));
        for(int j = 0; j < m; j ++){
            for(int i = 0; i < n; i ++){
                freq[j][grid[i][j]] ++;
            }
        }
        for(int j = 0; j < m; j ++){
            for(int i = 0; i < 10; i ++){
                freq[j][i] = n - freq[j][i];
            }
        }
        vector<vector<int>> dp(m, vector<int>(10, -1));
        int ans = INT_MAX;
        for(int i = 0; i < 10; i ++){
            ans = min(ans, solve(freq, 1, i, dp) + freq[0][i]);
        }
        return ans;
    }
};