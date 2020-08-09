// 1. Leetcode 242 有效的字母异位词
// 时间复杂度：O(n)，空间复杂度：O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<char> charmap(26,0);
        for (int i = 0; i < s.length(); i++)
            charmap[s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++)
            charmap[t[i] - 'a']--;
        for (int i = 0; i < 26; i++)
            if (charmap[i] != 0)
                return false;
        return true;
    }
};

// 2. Leetcode 1 两数之和
// 时间复杂度：O(n)，空间复杂度：O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map <int, int> Map;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (Map.find(target - nums[i]) != Map.end()) {
                ans.push_back(i);
                ans.push_back(Map[target - nums[i]]);
                return ans;
            }
            Map[nums[i]] = i;
        }
        return ans;
    }
};


// 3. Leetcode 589 N叉树的前序遍历
// 时间复杂度：O(n)，空间复杂度：O(n)

/*
///Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<Node*> TravelNode;
        TravelNode.push(root);
        while(!TravelNode.empty()){
            Node* TempNode = TravelNode.top();
            TravelNode.pop();
            if(TempNode != NULL)
                ans.push_back(TempNode -> val);
            vector<Node*> childrenNodes = TempNode -> children;
            int size = childrenNodes.size() - 1;
            for(int i = size; i >= 0; i--)
                TravelNode.push(childrenNodes[i]);
        }
        return ans;
    }
};

// 4. Leetcode 144 二叉树的前序遍历
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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<TreeNode*> TravelNodes;
        TravelNodes.push(root);
        while(!TravelNodes.empty()){
            TreeNode* TempNode = TravelNodes.top();
            TravelNodes.pop();
            ans.push_back(TempNode -> val);
            if(TempNode -> right != NULL)
                TravelNodes.push(TempNode -> right);
            if(TempNode -> left != NULL)
                TravelNodes.push(TempNode -> left);
        }
        return ans;
    }
};