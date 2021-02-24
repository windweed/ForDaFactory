/**
 * 字符串相关
 * 14最长公共前缀，28实现strstr()，35搜索插入位置
*/
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

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
};