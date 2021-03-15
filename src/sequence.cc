/**
 * @file 连续内存问题。包含数组和字符串。
 *       Array:
 *          1两数之和，26删除排序数组中的重复项，27移除元素，53最大子序和，
 *          88合并两个有序数组，118杨辉三角，167两数之和II。
 *       Strings:
 *          14最长公共前缀，28实现strstr()，35搜索插入位置，38外观数列，
 *          58最后一个单词的长度，1047删除字符串中所有相邻重复项
 *       
*/

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

class ArraySolution {
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
    vector<int> twoSum_v2(vector<int>& nums, int target) {
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
     * @brief leetcode 88 merge-soted-array 合并两个有序数组 easy
     *        给定两个有序整数数组nums1和nums2，将nums2合并到nums1中，使nums1成为一个
     *        有序数组。nums1和nums2的初始元素数量分别是m和n，可以假设nums1的空间
     *        大于等于m+n。
     * @example Input: nums1=[1,2,3,0,0,0],m=3,nums2=[2,5,6],n=3
     *          Output: [1,2,2,3,5,6]
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* sorted = new int[m + n];
        int p1 = 0, p2 = 0; // 下标
        int curr = 0;
        while (p1 < m || p2 < n) {
            if (p1 == m) {  // p1已结束
                curr = nums2[p2++];
            } else if (p2 == n) { // p2已结束
                curr = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                curr = nums1[p1++];
            } else {
                curr = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = curr;
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = sorted[i];
        }
        delete[] sorted;
    }
    
    /**
     * @brief leetcode 118 pascals-triangle 杨辉三角 easy
     *        生成杨辉三角的前n行。
     * @note 第n行的第i个数等于第n-1行的第i-1和第i个数之和。
    */
    vector<vector<int>> generate(int numRows) {
    auto result = vector<vector<int>>(numRows);
    for (int i = 0; i < numRows; i++) {
        vector<int>& curr_row = result[i];
        curr_row.resize(i + 1);              // 第i行有 i + 1 个数，下标为[0, i]
        curr_row.front() = curr_row.back() = 1;

        for (int j = 1; j < i; j++) {  // j 的下标范围是 [0, i], 但0和i都已赋1
            const vector<int>& prev_row = result[i - 1];
            curr_row[j] = prev_row[j - 1] + prev_row[j];
        }
    }
    return result;
}

    /**
     * @brief leetcode 167 two-sum-ii-input-array-is-sorted 两数之和II easy
     *        给定一个升序排列的整数数组numbers，从数组中找出两个数满足相加之和等于目标数。
     *        下标从1开始计数。可以假设每个输入对应的答案唯一，不能使用相同的元素。
     * @example Input: numbers=[2,7,11,15],target=9
     *          Output: 1,2
     * @note 双指针，反向查找。如果两个指针元素和小于target，左指针右移，否则右指针左移。
    */
    vector<int> twoSum2(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        int sum;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                break;
            }
            (sum < target) ? left++ : right--;
        }
        return vector<int> {left + 1, right + 1};
    }
};



class StrSolutioin {
public:
    /**
     * @brief leetcode 14 longest-common-prefix 最长公共前缀
     * @return 如果不存在公共前缀，返回空字符串。
    */
    string longestCommonPrefix(vector<string>& strs) {
        int cnt = strs.size();
        if (cnt == 0) {
            return "";
        }

        string lcp = strs[0];
        for (int i = 1; i < cnt; i++) {
            lcp = lcpTwoStr(lcp, strs[i]);
            if (lcp.empty()) {
                break;
            }
        }
        return lcp;
    }
    // helper function
    string lcpTwoStr(string str1, string str2) {
        int length = min(str1.length(), str2.length());
        int idx = 0;
        while (idx < length && str1.at(idx) == str2.at(idx)) {
            idx++;
        }
        return str1.substr(0, idx);
    }

    /**
     * @brief leetcode 28 implement-strstr 实现strstr easy
     * @return 如果不存在，返回-1。
    */
    int myStrStr(string haystack, string needle) {
        int hay_len = haystack.length();
        int n_len = needle.length();

        for (int i = 0; i < hay_len - n_len + 1; i++) {
            if (haystack.substr(i, n_len) == needle) {
                return i;
            }
        }
        return -1;
    }

    /**
     * @brief leetcode 35 search-insert-position 搜索插入位置 easy
     *      给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果不存在则
     *      返回将会被插入的位置。
     * @note 无重复元素。
    */
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.size();
    }

    /**
     * @brief leetcode 38 count-and-say 外观数列 easy
     *      给定一个正整数，输出外观数列的第n项。
     * @note 外观数列是一个整数序列，从数字1开始，序列中的每一项都是对前一项的描述。
     * @example 1.  1
     *          2.  11
     *          3.  21
     *          4.  1211
     *          5.  111221
    */
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        ostringstream s;
        string str_to_desc = countAndSay(n - 1);
        int slow = 0;
        for (int fast = 1; fast < str_to_desc.length(); fast++) {
            if (str_to_desc[slow] != str_to_desc[fast]) {
                s << fast - slow << str_to_desc[slow];
                slow = fast;
            }
        }
        // last one
        s << str_to_desc.length() - slow << str_to_desc[slow];
        return s.str();
    }

    /**
     * @brief leetcode 58 length-of-last-word 最后一个单词的长度 easy
     *      给定一个字符串，由若干单词组成，单词之间用空格隔开，返回字符串中
     *      最后一个单词的长度。如果不存在最后一个单词，返回0
     * @example 输入s = "hello world", 输出5;
     *          输入s = " ", 输出0
    */
    int lengthOfLastWord(string s) {
        istringstream is(s);
        string input;
        while (is >> input) {
            ;
        }
        return input.length();
    }

    /**
     * @brief leetcode 1047 remove-all-adjacent-duplicates-in-string
     *        删除字符串中所有相邻重复项 easy
     *        给定字符串，执行“重复项删除”操作，选择两个相邻且相同的字母并删除它们。
     *        在给定字符串上反复执行重复项删除操作，直到无法继续删除。
     * @return 完成所有“重复项删除”操作后的最终字符串。
     * @analyse: 由于是重复项，而且是两两删除，因此直接选择栈。对C++来说，string即可。
    */
    string removeDuplicates1047(string S) {
        string result = string();
        for (char const ch : S) {
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }

};
