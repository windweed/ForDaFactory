#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
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




};




























