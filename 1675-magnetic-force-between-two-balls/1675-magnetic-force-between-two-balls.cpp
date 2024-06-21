class Solution {
public:
    bool helper(vector<int> & arr, int k, int m){
        int prev = arr[0];
        int cnt = 1;
        for(int i = 1; i < arr.size(); i ++){
            if(arr[i] - prev >= m){
                cnt ++;
                prev = arr[i];
            }
        }
        return cnt >= k;
    }
    int maxDistance(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int l = 1;
        int r = 1000000000;
        int ans = -1;
        while(l <= r){
            int m = (l+r)/2;
            if(helper(arr, k, m)){
                ans = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return ans;
    }
};