#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

//1.https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/?envType=daily-question&envId=2025-04-08
class Solution01 {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> seen(128);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (seen[nums[i]]) {
                return i / 3 + 1;
            }
            seen[nums[i]] = true;
        }
        return 0;
    }
};

//2.https://leetcode.cn/problems/robot-bounded-in-circle/?envType=study-plan-v2&envId=programming-skills
class Solution02 {
public:
    bool isRobotBounded(string instructions) {
        int dist[4]{};
        int k = 0;
        for (char& c : instructions) {
            if (c == 'L') {
                k = (k + 1) % 4;
            }
            else if (c == 'R') {
                k = (k + 3) % 4;
            }
            else {
                ++dist[k];
            }
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || k;
    }
};

//3.https://leetcode.cn/problems/multiply-strings/?envType=study-plan-v2&envId=programming-skills
class Solution03 {
public:
    string multiply(string num1, string num2) {
        //�κ�����0��˽����Ϊ0
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n, 0);//������
        for (int i = m - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                //��i=m-1��j=n-1ʱj+i+1=m+n-1
                //��ʱ�������ô�:1.����д�±��ɸߵ���ʱans�ɵ�λ����λ�洢(��m+n-1�±괦Ϊans�ĸ�λ��,m+n-2�±괦Ϊans��ʮλ��,�Դ�����)
                //2.������н�λ����
                //��num1��ÿһλ���ֱַ���num2��ÿһλ���ֽ������
                ansArr[j + i + 1] += x * y;
                //���ansĳλ�������ִ��ڵ���10����Ҫ�����н�λ����
                if (ansArr[j + i + 1] >= 10) {
                    //ans�ĸ�λ��Ҫ���Ͻ�λ
                    ansArr[j + i] += ansArr[j + i + 1] / 10;
                    //����ansArr[j+i+1]�ж��,������λ��,��������λ����
                    ansArr[j + i + 1] %= 10;
                }
            }
        }

        //�ж����λ�Ƿ���0,������±�1��ʼ����,������±�0��ʼ����
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto& c : ans) {
            c += '0';
        }

        return ans;
    }
};

//4.https://leetcode.cn/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=programming-skills
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution04 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;

        return preHead->next;
    }
};

//5.https://leetcode.cn/problems/reverse-linked-list/?envType=study-plan-v2&envId=programming-skills
class Solution05 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* n1 = nullptr;
        ListNode* n2 = head;
        ListNode* n3 = head->next;

        while (n2 != nullptr) {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3 != nullptr) {
                n3 = n3->next;
            }
        }

        return n1;
    }
};

//6.https://leetcode.cn/problems/add-two-numbers/?envType=study-plan-v2&envId=programming-skills
class Solution06 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(0);
        ListNode* prev = preHead;
        int carrier = 0;

        while (l1 || l2 || carrier) {
            int sum = 0;
            sum += (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carrier;

            prev->next = new ListNode(sum % 10);
            prev = prev->next;

            carrier = sum / 10;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        ListNode* result = preHead->next;
        delete preHead;
        return result;
    }
};

//7.https://leetcode.cn/problems/add-two-numbers-ii/?envType=study-plan-v2&envId=programming-skills
class Solution07 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, * cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode* addTwo(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(0);
        ListNode* prev = preHead;
        int carrier = 0;
        while (l1 || l2 || carrier) {
            int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carrier;

            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            carrier = sum / 10;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }

        }
        ListNode* result = preHead->next;
        delete preHead;

        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1), l2 = reverseList(l2);
        ListNode* l3 = addTwo(l1, l2);
        return reverseList(l3);
    }
};

//8.https://leetcode.cn/problems/power-of-two/?envType=study-plan-v2&envId=primers-list
class Solution08 {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

//9.https://leetcode.cn/problems/transpose-matrix/?envType=study-plan-v2&envId=primers-list
class Solution09 {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(row, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};

//10.https://leetcode.cn/problems/peak-index-in-a-mountain-array/?envType=study-plan-v2&envId=primers-list
class Solution10 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int index = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                index = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return index;
    }
};

//11.https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=study-plan-v2&envId=binary-search
class Solution11 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, last = -1;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return vector<int>{ first, last };
    }
};