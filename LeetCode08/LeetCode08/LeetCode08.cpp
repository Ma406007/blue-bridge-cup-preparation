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
       //���ö��ֲ����ҵ���һ������snap_id��Ԫ��,�ҵ��󷵻ص�����
       auto num = upper_bound(Array[index].begin(), this->Array[index].end(), make_pair(snap_id + 1, -1));
       //����ж�num�Ƿ�����Ԫ�صĵ�����,������򷵻�pair��snap_id==0ʱ��value,���򷵻�num��������ǰһ��Ԫ��(����Ҳ��֤�˿��Ի�ȡ����set�����������Ԫ��)
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

            //���nums[mid]==targetֱ�ӷ���mid�±�
            if (nums[mid] == target) {
                return mid;
            }
            //���nums[0]<=nums[mid]˵��[0,mid]����������������
            if (nums[0] <= nums[mid]) {
                //���target���ڵ���nums[0]����С��nums[mid]˵��targetλ�ڵ�ǰ��������������
                if (nums[0] <= target && target < nums[mid]) {
                    //��������right������mid-1
                    right = mid - 1;
                }
                //���target����nums[mid]����С�ڵ���nums[n-1]˵��targetλ�ڵ�ǰ������Ұ�������
                else {
                    //��������left������mid+1
                    left = mid + 1;
                }
            }
            //����[mid+1,n-1]�������
            else {
                //���target����nums[mid]����С�ڵ���nums[n-1]˵��targetλ�ڵ�ǰ������Ұ�������
                if (nums[mid] < target && target <= nums[n - 1]) {
                    //��������left������mid+1
                    left = mid + 1;
                }
                //���target���ڵ���nums[0]����С��nums[mid]˵��targetλ�ڵ�ǰ��������������
                else {
                    //��������right������mid-1
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

//3.https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/?envType=study-plan-v2&envId=binary-search
/*
    ��x=nums[mid]�����ڶ���ȡ��������
    ������Ҫ�ж�x��������Сֵ��λ�ù�ϵ����˭�����˭���ұ�
    ��x�뵱ǰ�������һ����nums[right]�ȴ�С��
    ���x>nums[right]����ô�����Ƴ����½��ۣ�
      numsһ�����ֳ��������������Σ�
      ��һ�ε�����Ԫ�ؾ����ڵڶ��ε�����Ԫ�أ�
      x�ڵ�һ�Ρ�
      ��Сֵ�ڵڶ��Ρ�
      ����xһ������Сֵ����ߡ�
      ���x��nums[right]����ôxһ���ڵڶ��Ρ�������nums���ǵ������飬��ʱֻ��һ�Ρ���
      xҪô����Сֵ��Ҫô����Сֵ�ұߡ�
    ���ԣ�ֻ��Ҫ�Ƚ�x��nums[right]�Ĵ�С��ϵ�ͼ�ӵ�֪����x��������Сֵ��λ�ù�ϵ���Ӷ����ϵ���С������Сֵ����λ�õķ�Χ�����ҵ�������Сֵ��
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

            //���nums[mid]<nums[right]˵����Сֵһ����[left,mid]��(�������ų�nums[mid]Ϊ��Сֵ,��Ϊ��벿�ֺ��Ұ벿�ֶ����ϸ������)
            if (nums[mid] < nums[right]) {
                //��ʱ����right��mid
                right = mid;
            }
            //���nums[mid]==nums[right]�޷��ж���Сֵ����벿�ֻ����Ұ벿��,��Ҫ����΢��
            else if (nums[mid] == nums[right]) {
                //midһ����right�����,����Сֵ(��ת��)���ǳ�����mid����,ȥ��nums�����һ��Ԫ�ؼ�ȥ��right�ұߵ�һ��Ԫ��
                //���׵õ�:right�ұߵ�Ԫ����һ�����ڵ�����Сֵ��
                //�����Ͳ�������ȥ����Сֵ:
                //1.���right,right+1�±����ڴ���Ԫ������Сֵ,��ônums[mid]Ҳһ������Сֵ
                //2.���ȥ������������Сֵ(���������������),�Ǿ��ų���һ�������
                right = right - 1;
            }
            //���nums[mid]>nums[right]˵����Сֵһ����[mid+1,right]��
            else {
                //��ʱ����left��mid+1
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