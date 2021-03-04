/**
 * 1两数之和，69x的平方根，70爬楼梯
*/
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class OtherSolution {
public:
    /**
     * @brief leetcode 1 two sum 两数之和 easy
     *      给定一个整数数组nums和一个整数目标值，在数组中找出和为目标值的那两个整数，
     *      并返回它们的下标。
     * @note 可以假设每种输入只会对应一个答案。同一个元素不能使用两遍。
    */
    vector<int> towSum(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
    // 解法2
    vector<int> twoSum2(vector<int>& nums, int target) {
        auto m = unordered_map<int, int>();
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                return {i, it->second};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }

    /**
     * @brief leetcode 69 sqrtx x的平方根 easy
     *      只保留整数
    */
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int left = 0, right = x, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    /**
     * @brief leetcode 70 climbing-stairs 爬楼梯 easy
     *      每次可以爬1或2级台阶，问有多少种方法可以走完n级楼梯(n > 0)
     * @note 斐波那契数列
    */
    int climbStairs(int n) {
        int prev1 = 0, prev2 = 0, result = 1;
        while (n--) {
            prev1 = prev2;
            prev2 = result;
            result = prev1 + prev2;
        }
        return result;
    }
    
};




























