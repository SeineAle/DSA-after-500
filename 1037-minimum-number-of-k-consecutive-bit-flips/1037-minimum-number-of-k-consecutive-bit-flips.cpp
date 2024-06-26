class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ends(n, 0);
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            if((nums[i] + cnt)%2 == 0){
                if(i + k - 1 >= n) return -1;
                cnt ++;
                ans ++;
                ends[i + k - 1] = 1;
            }
            if(ends[i]) cnt --;
        }
        return ans;
    }
};