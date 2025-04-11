#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//1.https://leetcode.cn/problems/snapshot-array/?envType=study-plan-v2&envId=binary-search
class SnapshotArray {
private:
   int snap_id;
   vector<vector<pair<int, int>>> Array;

public:
   SnapshotArray(int length) {
       snap_id = 0;
       Array.resize(length);
   }

   void set(int index, int val) {
       Array[index].emplace_back(snap_id, val);
   }

   int snap() {
       return snap_id++;
   }

   int get(int index, int snap_id) {
       //利用二分查找找到第一个大于snap_id的元素,找到后返回迭代器
       auto num = upper_bound(Array[index].begin(), this->Array[index].end(), make_pair(snap_id + 1, -1));
       //随后判断num是否是首元素的迭代器,如果是则返回pair中snap_id==0时的value,否则返回num迭代器的前一个元素(这样也保证了可以获取调用set函数后的最新元素)
       return num == Array[index].begin() ? 0 : prev(num)->second;
   }
};
/**
* Your SnapshotArray object will be instantiated and called as such:
* SnapshotArray* obj = new SnapshotArray(length);
* obj->set(index,val);
* int param_2 = obj->snap();
* int param_3 = obj->get(index,snap_id);
*/

//2.https://leetcode.cn/problems/search-in-rotated-sorted-array/?envType=study-plan-v2&envId=binary-search
class Solution02 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            //如果nums[mid]==target直接返回mid下标
            if (nums[mid] == target) {
                return mid;
            }
            //如果nums[0]<=nums[mid]说明[0,mid]这个区间内是有序的
            if (nums[0] <= nums[mid]) {
                //如果target大于等于nums[0]并且小于nums[mid]说明target位于当前数组的左半区间内
                if (nums[0] <= target && target < nums[mid]) {
                    //则将右区间right缩短至mid-1
                    right = mid - 1;
                }
                //如果target大于nums[mid]并且小于等于nums[n-1]说明target位于当前数组的右半区间内
                else {
                    //则将左区间left增加至mid+1
                    left = mid + 1;
                }
            }
            //否则[mid+1,n-1]是有序的
            else {
                //如果target大于nums[mid]并且小于等于nums[n-1]说明target位于当前数组的右半区间内
                if (nums[mid] < target && target <= nums[n - 1]) {
                    //则将左区间left增加至mid+1
                    left = mid + 1;
                }
                //如果target大于等于nums[0]并且小于nums[mid]说明target位于当前数组的左半区间内
                else {
                    //则将右区间right缩短至mid-1
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

//3.https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/?envType=study-plan-v2&envId=binary-search
/*
    设x=nums[mid]是现在二分取到的数。
    我们需要判断x和数组最小值的位置关系：即谁在左边谁在右边
    把x与当前区间最后一个数nums[right]比大小：
    如果x>nums[right]，那么可以推出以下结论：
      nums一定被分成左右两个递增段；
      第一段的所有元素均大于第二段的所有元素；
      x在第一段。
      最小值在第二段。
      所以x一定在最小值的左边。
      如果x≤nums[right]，那么x一定在第二段。（或者nums就是递增数组，此时只有一段。）
      x要么是最小值，要么在最小值右边。
    所以，只需要比较x和nums[right]的大小关系就间接地知道了x和数组最小值的位置关系，从而不断地缩小数组最小值所在位置的范围二分找到数组最小值。
*/
class Solution03 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

//4.https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/?envType=study-plan-v2&envId=binary-search
class Solution04 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            //如果nums[mid]<nums[right]说明最小值一定在[left,mid]中(但并不排除nums[mid]为最小值,因为左半部分和右半部分都是严格递增的)
            if (nums[mid] < nums[right]) {
                //此时调整right至mid
                right = mid;
            }
            //如果nums[mid]==nums[right]无法判断最小值在左半部分还是右半部分,需要进行微调
            else if (nums[mid] == nums[right]) {
                //mid一定在right的左边,而最小值(旋转点)总是出现在mid附近,去掉nums的最后一个元素即去掉right右边的一个元素
                //容易得到:right右边的元素是一定大于等于最小值的
                //这样就不会碰巧去掉最小值:
                //1.如果right,right+1下标所在处的元素是最小值,那么nums[mid]也一定是最小值
                //2.如果去掉的数不是最小值(大多数情况都是如此),那就排除了一个错误答案
                right = right - 1;
            }
            //如果nums[mid]>nums[right]说明最小值一定在[mid+1,right]中
            else {
                //此时调整left至mid+1
                left = mid + 1;
            }
        }

        return nums[left];
    }
};

//5.https://leetcode.cn/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=binary-search
class Solution05 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int x = matrix[mid / n][mid % n];

            if (x < target) {
                low = mid + 1;
            }
            else if (x > target) {
                high = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

//6.https://leetcode.cn/problems/sqrtx/?envType=study-plan-v2&envId=binary-search
class Solution06 {
public:
    int mySqrt(int x) {
        int left = 0, right = x, ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

//7.https://leetcode.cn/problems/arranging-coins/?envType=study-plan-v2&envId=binary-search
class Solution07 {
public:
    int arrangeCoins(int n) {
        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if ((long long)mid * (mid + 1) <= (long long)2 * n) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

//8.https://leetcode.cn/problems/climbing-stairs/?envType=study-plan-v2&envId=dynamic-programming
class Solution08 {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

//9.https://leetcode.cn/problems/fibonacci-number/?envType=study-plan-v2&envId=dynamic-programming
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

//10.https://leetcode.cn/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=dynamic-programming
class Solution10 {
public:
    int tribonacci(int n) {
        if (n < 2) {
            return n;
        }
        if (n == 2) {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }
};