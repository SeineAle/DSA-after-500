#define ll long long
#define vll vector<ll>
class SegmentTree {
private:
    vll tree;
    vll data;
    ll n;

    void buildTree(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            ll mid = (start + end) / 2;
            ll leftChild = 2 * node + 1;
            ll rightChild = 2 * node + 2;
            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);
            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    void updateTree(ll node, ll start, ll end, ll idx, ll value) {
        if (start == end) {
            data[idx] = value;
            tree[node] = value;
        } else {
            ll mid = (start + end) / 2;
            ll leftChild = 2 * node + 1;
            ll rightChild = 2 * node + 2;

            if (start <= idx && idx <= mid) {
                updateTree(leftChild, start, mid, idx, value);
            } else {
                updateTree(rightChild, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[leftChild], tree[rightChild]);
        }
    }

    ll queryTree(ll node, ll start, ll end, ll L, ll R) {
        if (R < start || end < L) {
            return LLONG_MIN;
        }

        if (L <= start && end <= R) {
            return tree[node];
        }
        ll mid = (start + end) / 2;
        ll leftChild = 2 * node + 1;
        ll rightChild = 2 * node + 2;

        ll leftQuery = queryTree(leftChild, start, mid, L, R);
        ll rightQuery = queryTree(rightChild, mid + 1, end, L, R);
        return max(leftQuery, rightQuery);
    }

public:
    SegmentTree(const vector<int>& input) {
        n = input.size();
        data.resize(n);
        for(int i = 0; i < n; i ++) data[i] = input[i];
        tree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    void update(ll idx, ll value) {
        updateTree(0, 0, n - 1, idx, value);
    }

    ll query(ll L, ll R) {
        return queryTree(0, 0, n - 1, L, R);
    }
};
class Solution {
public:
    
    long long numberOfSubarrays(vector<int>& nums) {
        map<ll ,vll> freq;
        ll n = nums.size();
        for(ll i = 0; i < n; i ++){
            freq[nums[i]].push_back(i);
        }
        SegmentTree ST(nums);
        ll ans = 0;
        for(auto & p : freq){
            ll el = p.first;
            ll l = 0;
            for(ll r = 1; r < p.second.size(); r ++){
                ll el_ = ST.query(p.second[l], p.second[r]);
                if(el_ == el){
                    ans += r-l;
                }else{
                    l = r;
                }
            }
        }
        return ans + n;
    }
};