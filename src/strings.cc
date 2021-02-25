/**
 * 字符串相关
 * 14最长公共前缀，28实现strstr()，35搜索插入位置，38外观数列，58最后一个单词的长度
*/
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>

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


};