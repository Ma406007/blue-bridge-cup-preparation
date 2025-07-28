#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/count-number-of-maximum-bitwise-or-subsets/?envType=daily-question&envId=2025-07-28
class Solution1 {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //stateNumberΪ�ǿ��Ӽ���Ŀ,һ����2 ^ n - 1 ��
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                //��iλֵΪ1���ʾ���Ӽ�ѡȡ��ӦԪ��,����ѡȡ
                if (((i >> j) & 1) == 1) {
                    cur |= nums[j];
                }
            }

            //�ҵ������������Ӽ�����
            if (cur == maxValue) {
                cnt++;
            }
            //�и����ֵ��������ֵ���ҽ��Ӽ�������Ŀ����Ϊ1
            else if (cur > maxValue) {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};

class Solution2 {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        this->maxOr = 0;
        this->cnt = 0;

        dfs(0, 0);

        return cnt;
    }

    //pos:��ǰ�±� orVal:��ǰ�±�֮ǰ��ĳ���Ӽ���λ��ֵ
    void dfs(int pos, int orVal) {
        if (pos == nums.size()) {
            if (orVal > maxOr) {
                maxOr = orVal;
                cnt = 1;
            }
            else if (orVal == maxOr) {
                cnt++;
            }

            return;
        }

        dfs(pos + 1, orVal | nums[pos]);
        dfs(pos + 1, orVal);
    }

private:
    vector<int> nums;
    int maxOr, cnt;
};

//2.https://www.lanqiao.cn/problems/5888/learning/?page=1&first_category_id=1&tags=%E6%9E%9A%E4%B8%BE,%E6%A8%A1%E6%8B%9F,%E5%89%8D%E7%BC%80%E5%92%8C,%E5%B7%AE%E5%88%86,%E4%BA%8C%E5%88%86,%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2,%E8%B4%AA%E5%BF%83,%E4%BD%8D%E8%BF%90%E7%AE%97,%E5%8F%8C%E6%8C%87%E9%92%88&tag_relation=union&sort=difficulty&asc=1
/*
* ����˼·:
* �ȼ���k=2��k=3���ּ��ξ�Ҫ����k-1��ָ�룬��ֵ��sum�͵��ڸ�������֮��
* k=2�����������2�Σ�����һ��ָ��i��
*   sum=(a[i]-a[0])+(a[n-1]-a[i+1])=(a[n-1]-a[0])+(a[i]-a[i-1])
*   ��֪a[n-1]��a[0]Ϊ��ֵ������Ҫ��sum��С������ת��Ϊ��a[i]-a[i+1]����Сֵ����������ֱ����һ������b���������Ԫ�ؼ�Ĳ�ֵ��b�����ѡ��һ����С��ֵ
* k=3�����������3�Σ���������ָ��i��j��
*   sum=(a[i]-a[0])+(a[j]-a[i+1])+(a[n-1]-a[j+1])=(a[n-1]-a[0])+(a[i]-a[i+1])+(a[j]-a[j+1])
*   ͬ��a[n-1]��a[0]Ϊ��ֵ������Ҫ��sum��С������ת��Ϊ��a[i]-a[i+1]��a[j]-a[j+1]����Сֵ������b���������Ԫ�ؼ�Ĳ�ֵ��b�����ѡ��������С��ֵ
* �ƹ㵽һ�������
*   a[n-1]��a[0]Ϊ��ֵ������Ҫ��sum��С������ת��Ϊ��a[i1]-a[i1+1]��a[i2]-a[i2+1],...,a[in]-a[in+1]����Сֵ������b���������Ԫ�ؼ�Ĳ�ֵ��b�����ѡ��k-1����С��ֵ
*/
int n, k;
int a[100005], b[100005];
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n - 1; j++) {
        b[j] = a[j] - a[j + 1];
    }
    sort(b, b + n - 1);

    int sum = a[n - 1] - a[0];
    for (int i = 0; i < k - 1; i++) {
        sum += b[i];
    }

    cout << sum << endl;
    return 0;
}

//3.https://www.lanqiao.cn/problems/3841/learning/?page=1&first_category_id=1&tags=%E6%9E%9A%E4%B8%BE,%E6%A8%A1%E6%8B%9F,%E5%89%8D%E7%BC%80%E5%92%8C,%E5%B7%AE%E5%88%86,%E4%BA%8C%E5%88%86,%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2,%E8%B4%AA%E5%BF%83,%E4%BD%8D%E8%BF%90%E7%AE%97,%E5%8F%8C%E6%8C%87%E9%92%88&tag_relation=union&sort=difficulty&asc=1
int main(int argc, char* argv[])
{
    char a[8][8] = { '0' };

    for (int i = 1; i <= 7; i++)
    {
        if (i == 1 || i == 2 || i == 6 || i == 7)
        {
            for (int j = 3; j <= 5; j++)
            {
                scanf(" %c", &a[i][j]);
            }
        }
        else
        {
            for (int j = 1; j <= 7; j++)
            {
                scanf(" %c", &a[i][j]);
            }
        }
    }

    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (a[i][j] == '1')
            {
                if (a[i - 1][j] == '1' && a[i - 2][j] == '0' || a[i + 1][j] == '1' && a[i + 2][j] == '0' || a[i][j - 1] == '1' && a[i][j - 2] == '0' || a[i][j + 1] == '1' && a[i][j + 2] == '0')
                {
                    printf("no");
                    return 0;
                }
            }
        }
    }

    printf("yes");
    return 0;
}