// 1. Leetcode 64 最小路径和
// 时间复杂度：O(m*n)，空间复杂度：O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int size = grid.size();
        if (size == 0)
            return 0;
        vector<vector<int>> DP(size, vector<int> (grid[0].size(), 0));
        DP[0][0] = grid[0][0];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j > 0)
                    DP[i][j] = DP[i][j-1] + grid[i][j];
                else if (i > 0 && j ==0)
                    DP[i][j] = DP[i-1][j] + grid[i][j];
                else if (i > 0 && j >0)
                    DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
            }
        }
        return DP[size-1][grid[0].size()-1];
    }
};

// 2. Leetcode 91 解码方法
// 时间复杂度：O(n)，空间复杂度：O(1)

class Solution {
public:
    int numDecodings(string s) {
        int Len = s.length();
        if (Len == 0)
            return 0;
        if (s[0] == '0')
            return 0;
        int pre = 1, now = 1;
        for (int i = 1; i < Len; i++) {
            int temp = now;
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2')
                    now = pre;
                else return 0;
            }
            else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6'))
                now = pre + now;
            pre = temp;
        }
        return now;
    }
};

// 3. Leetcode 647 回文子串
// 时间复杂度：O(n^2)，空间复杂度：O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n <= 1)
            return n;
        int ans = 0;
        vector<vector<int>> DP (n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i < 2 || DP[i+1][j-1])) {
                    DP[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};