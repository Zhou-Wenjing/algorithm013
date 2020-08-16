// 1. Leetcode 236 二叉树的最近公共祖先
// 时间复杂度：O(n)，空间复杂度：O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;
        TreeNode* Left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* Right = lowestCommonAncestor(root -> right, p, q);
        if (Left && Right)
            return root;
        else return Left ? Left : Right;
    }
};

// 2. Leetcode 105 从前序与中序遍历序列构造二叉树
// 时间复杂度：O(n)，空间复杂度：O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map <int, int> idx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for (int i = 0; i < size; i++)
            idx[inorder[i]] = i;
        return mybuildTree(preorder, 0, size - 1, 0, size - 1);
    }
    TreeNode* mybuildTree(vector<int>& preorder, int preleft, int preright, int inleft, int inright) {
        if (preleft > preright)
            return NULL;
        int preroot = preleft;
        int inroot = idx[preorder[preroot]];
        int left_subtree_size = inroot - inleft;
        TreeNode* root = new TreeNode(preorder[preroot]);
        root -> left = mybuildTree(preorder, preleft + 1, preleft + left_subtree_size, inleft, inroot - 1);
        root -> right = mybuildTree(preorder, preleft + left_subtree_size + 1, preright, inroot + 1, inright);
        return root;
    }
};

// 3. Leetcode 77 组合
// 时间复杂度：O(k*C(n,k))，空间复杂度：O(k*C(n,k))

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || k > n)
            return ans;
        vector<int> path;
        dfs(n, k, 1, path);
        return ans;
    }
    void dfs(int n, int k, int start, vector<int>& path) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(n, k, i+1, path);
            path.pop_back();
        }
    }
};

// 4. Leetcode 46 全排列

// 方法一：回溯
// 时间复杂度：O(n*n!)，空间复杂度：O(n*n!)

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return ans;
        vector<int> used(size, 0);
        vector<int> path;
        dfs(nums, path, used, 0, size);
        return ans;
    }
    void dfs(vector<int>& nums, vector<int>& path, vector<int>& used, int depth, int size) {
        if (depth == size) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < size; i++) {
            if (used[i])
                continue;
            path.push_back(nums[i]);
            used[i] = 1;
            dfs(nums, path, used, depth + 1, size);
            path.pop_back();
            used[i] = 0;
        }
    }
};

// 方法二：交换法（其实也用了回溯）
// 时间复杂度：O(n*n!)，空间复杂度：O(n*n!)
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return ans;
        permutation(nums, 0, size - 1);
        return ans;
    }
    void permutation(vector<int>& nums, int start, int end) {
        if (start == end) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i <= end; i++) {
            swap(nums[i], nums[start]);
            permutation(nums, start + 1, end);
            swap(nums[i], nums[start]);
        }
    }
};

// 5. Leetcode 47 全排列II
// 时间复杂度：O(n*n!)，空间复杂度：O(n*n!)

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return ans;
        permutation(nums, 0, size - 1);
        return ans;
    }
    void permutation(vector<int>& nums, int start, int end) {
        if (start == end) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> set;
        for (int i = start; i <= end; i++) {
            if (set.count(nums[i]) == 1)
                continue;
            set.insert(nums[i]);
            swap(nums[i], nums[start]);
            permutation(nums, start + 1, end);
            swap(nums[i], nums[start]);
        }
    }
};
