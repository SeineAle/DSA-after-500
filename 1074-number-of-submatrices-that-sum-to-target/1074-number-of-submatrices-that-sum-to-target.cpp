class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int t) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<unordered_map<int, int>>> alpha(m + 1, vector<unordered_map<int, int>>(m + 1));
        vector<vector<int>> gamma(n+1, vector<int>(m+1, 0));
        vector<int> delta(m+1, 0);

        int ans = 0;
        for(int i = 0; i <= m; i ++){
            for(int j = 0; j <= m; j ++){
                alpha[i][j][0] ++;
            }
        }

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                delta[j+1] += matrix[i][j];
                gamma[i+1][j+1] = gamma[i+1][j] + delta[j+1];

                for(int k = 0; k <= j; k ++){
                    int req = gamma[i+1][j+1] - gamma[i+1][k] - t;
                    if(alpha[j+1][k].find(req) != alpha[j+1][k].end())ans += alpha[j+1][k][req];
                    alpha[j+1][k][gamma[i+1][j+1] - gamma[i+1][k]] ++;
                }
            }
        }
        
        return ans;
    }
};