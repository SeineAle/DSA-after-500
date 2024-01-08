class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        int maxRemovals = INT_MIN;
        int ans = nums[0];
        for(int i = nums.size()-1; i >= 0; i --){
            if(mp.find(nums[i]%space) != mp.end()){
                if(mp[nums[i] % space] + 1 >= maxRemovals){
                    maxRemovals = mp[nums[i] % space] + 1;
                    ans = nums[i];
                }
            }
            mp[nums[i] % space] ++;
        }
        return ans;
    }
};