//第1周作业

// 1. Leetcode 26 删除数组中的重复项

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int start = 1, end = 1;
        while(start < size){
            if(nums[start] != nums[start - 1]){
                nums[end] = nums[start];
                end++;
            }
            start++;
        }
        return end;
    }
};

// 2. Leetcode 189 旋转数组

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// 3. Leetcode 21 合并两个有序链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 ==nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if(l1 -> val < l2 -> val) {
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
        else {
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }
};

// 4. Leetcode 88 合并两个有序数组

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;
        m = m - 1;
        n = n - 1;
        while (n >= 0) {
            nums1[p--] = (m < 0 || nums1[m] < nums2[n]) ? nums2[n--] : nums1[m--];
        }
    }
};

// 5. Leetcode 1 两数之和

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

// 6. Leetcode 283 移动零

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 0, size = nums.size();
        for (; start < size; start++) {
            if (nums[start] != 0)
                nums[end++] = nums[start];
        }
        for (; end < size; end++) 
            nums[end] = 0;
    }
};

// 7. Leetcode 66 加一

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};


// 8. Leetcode 641 设计循环双端队列

class MyCircularDeque {
private:
    vector<int> arr;
    int front, rear, size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        arr.resize(k+1);
        front = 0;
        rear = 0;
        size = k+1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        front = (front - 1 + size) % size;
        arr[front] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        arr[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        rear = (rear - 1 + size) % size;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return arr[(rear - 1 + size) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
