#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long 

class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        ll ans = nums[0]; k --; dist ++;
        int n = nums.size();
        ordered_set os;
        for(int i = 1; i <= dist; i ++){
            os.insert(nums[i]);
        }
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += *os.find_by_order(i);
        }
        ans += sum;
        for(int i = 1; i < n-dist; i ++){
            int a = nums[i];
            int b = nums[i+dist];

            if(os.order_of_key(a) < k){
                sum -= a;
                sum += *os.find_by_order(k);
            }
            os.erase(os.upper_bound(a));

            os.insert(b);
            if(os.order_of_key(b) < k){
                sum += b;
                sum -= *os.find_by_order(k);
            }

            ans = min(ans, sum + nums[0]);
        }

        return ans;
    }
};