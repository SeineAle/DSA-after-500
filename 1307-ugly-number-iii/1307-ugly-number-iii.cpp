class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) { 
        return (a / gcd(a, b)) * b; 
    }

    long long ck(long long a, long long b, long long c, long long m) {
        return m / a + m / b + m / c 
               - m / lcm(a, b) 
               - m / lcm(a, c) 
               - m / lcm(b, c) 
               + m / lcm(a, lcm(b, c));
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long lo = 1;
        long long hi = 2 * 1e15;
        long long ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (ck(a, b, c, mid) < n) {
                lo = mid + 1;
            } else {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};