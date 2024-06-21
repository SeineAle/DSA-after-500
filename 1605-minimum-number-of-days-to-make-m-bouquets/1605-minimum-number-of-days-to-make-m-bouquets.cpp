class Solution {
public:
    bool helper(vector<int> & arr, int m, int k, int d){
        int n = arr.size();
        vector<bool> avail(n, false);
        for(int i = 0; i < n; i ++){
            if(arr[i] <= d) avail[i] = true;
        } avail.push_back(0);
        int cntOne = 0;
        vector<int> alpha;
        for(int i = 0; i <= n; i ++){
            if(avail[i]){
                cntOne ++;
            }else{
                if(cntOne)alpha.push_back(cntOne);
                cntOne = 0;
            }
        }
        int cnt = 0;
        for(auto el : alpha){
            cnt += el/k;
        }
        return cnt >= m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int l = 1;
        int r = 1000000000;
        int ans = -1;
        while(l <= r){
            int d = (l + r) / 2;
            if(helper(arr, m, k, d)){
                ans = d;
                r = d-1;
            }else{
                l = d+1;
            }
        }
        return ans;
    }
};