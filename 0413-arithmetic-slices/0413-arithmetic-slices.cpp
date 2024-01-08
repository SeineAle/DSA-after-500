class Solution {
public:
    vector<int>dp;
    vector<int> nums;
    int solve(int i){
        if(i < 2) return 0;
        if(dp[i] != -1) return dp[i];
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) return dp[i] = solve(i-1) + 1;
        int temp = solve(i-1);
        return dp[i] = 0;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        if(n < 3) return 0;
        dp.resize(n, -1);
        int sum = 0;
        int temp = solve(n-1);
        for(auto d : dp){
            if(d!= -1) sum += d;
        }
        return sum;
    }
};