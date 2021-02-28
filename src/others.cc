/**
 * 1两数之和，26删除排序数组中的重复项，27移除元素，53最大子序和，69x的平方根，70爬楼梯
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
     * @brief leetcode 26 remove-duplicates-from-sorted-array 删除排序数组中的重复项
     *      要求原地删除，不能使用额外数组空间，返回移除后数组的新长度。要求O(1)额外空间。
     *      easy
     * @example 给定[0,0,1,1,1,2,2,3,3,4], 修改为[0,1,2,3,4],返回5。
     * @note 快慢指针
    */
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        int slow = 0, fast = 1;
        for (; fast < len; fast++) {
            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }

    /**
     * @brief leetcode 27 remove-element 移除元素 easy
     *      给定一个数组和一个值，原地移除所有数值等于val的元素，并返回移除后数组的新长度
    */
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        int slow = 0, fast = 0;
        for (; fast < len; fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }

    /**
     * @brief leetcode 53 maximum-subarray 最大子序和 easy
     *      给定一个整数数组，找到一个具有最大和的连续子数组，返回其最大和
     * @example 输入 nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4],
     *      连续子数组[4, -1, 2, 1]的和最大，为6。因此返回6。
    */
    int maxSubArray(vector<int>& nums) {
        int pre = 0, max_ans = nums[0];
        for (int const& x : nums) {
            pre = max(pre + x, x);
            max_ans = max(max_ans, pre);
        }
        return max_ans;
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




























