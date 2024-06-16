class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long curr = 1;
        long long cnt = 0;
        long long idx = 0;
        long long sum = 0;
        while(curr < n){
            curr = sum + 1;
            while(idx < nums.size() && nums[idx] <= curr){
                sum += nums[idx];
                curr = sum + 1;
                idx ++;
            }
            if(curr > n) break;
            cnt ++;
            sum += curr;
        }
        return cnt;
    }
};