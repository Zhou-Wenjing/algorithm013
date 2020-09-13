// 1. Leetcode 208 实现Trie（前缀树）

class Trie {
private:
    bool isEnd;
    Trie* next[26];
    
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node -> next[c-'a'] == NULL)
                node -> next[c-'a'] = new Trie();
            node = node -> next[c-'a'];
        }
        node -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node -> next[c-'a'];
            if (node == NULL)
                return false;
        }
        return node -> isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node -> next[c-'a'];
            if (node == NULL)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// 2. Leetcode 547 朋友圈
// 时间复杂度：O(n^2)，空间复杂度：O(n);

class Solution {
private:
    int parent[201];

    void make_set(int n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find_set(int i) {
        if (i == parent[i])
            return i;
        return parent[i] = find_set(parent[i]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }

public:
    int findCircleNum(vector<vector<int>>& M) {
        int i, j, groups = 0, n = M.size();
        make_set(n);
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (M[i][j])
                    union_sets(i, j);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == parent[i])
                groups++;
        }
        return groups;
    }
};

// 3. Leetcode 200 岛屿数量
// 时间复杂度：O(mn)，空间复杂度：O(mn)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        int amount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    amount++;
                    DFSMark(grid, i, j);
                }
            }
        }
        return amount;
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