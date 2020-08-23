// 1. Leetcode 860 柠檬水找零
// 时间复杂度：O(n)，空间复杂度: O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size = bills.size();
        if (size == 0)
            return true;
        if (bills[0] != 5)
            return false;
        int five = 0, ten = 0;
        for (int i = 0; i < size; i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five == 0)
                    return false;
                else {
                    five--;
                    ten++;
                }
            }
            else {
                if (five == 0)
                    return false;
                if (ten != 0) {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                    five -= 3;
                else return false;
            }
        }
        return true;
    }
};

// 2. Leetcode 122 买卖股票的最佳时机II
// 时间复杂度：O(n)，空间复杂度：O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size <= 1)
            return 0;
        int profit = 0;
        for (int i = 1; i < size; i++) {
            if (prices[i] > prices[i-1])
                profit += (prices[i] - prices[i-1]);
        }
        return profit;
    }
};

// 3. Leetcode 455 分发饼干
// 时间复杂度：O(n*logn)，空间复杂度：O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gsize = g.size(), ssize = s.size(), num = 0;
        for (int i = 0, j = 0; i < gsize && j < ssize;) {
            if (g[i] <= s[j]) {
                num++;
                i++;
                j++;
            }
            else if (g[i] > s[j])
                j++;
        }
        return num;
    }
};

// 4. Leetcode 200 岛屿数量
// 时间复杂度：O(MN)，空间复杂度：O(MN)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    DFSMark(grid, i, j);
                    count++;
                }
        return count;
    }
    void DFSMark(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        DFSMark(grid, i-1, j);
        DFSMark(grid, i+1, j);
        DFSMark(grid, i, j-1);
        DFSMark(grid, i, j+1);
    }
};

// 5. Leetcode 55 跳跃游戏
// 时间复杂度：O(n)，空间复杂度：O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return true;
        int end = size - 1;
        for (int i = size - 1; i >= 0; i--) {
            if (nums[i] + i >= end) {
                end = i;
            }
        }
        if (end == 0)
            return true;
        else return false;
    }
};