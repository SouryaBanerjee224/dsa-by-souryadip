class Solution {
public:
   int m, n;
    vector<vector<int>> dp;

    int solve(vector<int>& a, vector<int>& b, int i, int j) {
        if (i == m || j == n) return -1e9;
        if (dp[i][j] != -1e9) return dp[i][j];

        int prod = a[i] * b[j];

        int takeBoth = prod + solve(a, b, i + 1, j + 1);
        int startNew = prod;
        int skipI = solve(a, b, i + 1, j);
        int skipJ = solve(a, b, i, j + 1);

        return dp[i][j] = max({startNew, takeBoth, skipI, skipJ});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        dp.assign(m, vector<int>(n, -1e9));
        return solve(nums1, nums2, 0, 0);
    }
};