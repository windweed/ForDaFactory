/**
 * @file 整数相关
 * 7整数反转, 9回文数，13罗马数字转整数
*/
#include <cstdint>
#include <string>

using namespace std;

class IntegerSolution {
public:
    /**
     * @brief leetcode 7 reverse-integer 整数反转 easy
     * @note 给你一个32的有符号整数 @p x ，返回x每位上的数字反转后的结果。
     *      如果反转后超过32位的有符号整数范围，返回0。
     * @example 输入x = 123, 输出321。
     *      输入x = -123, 输出-321。
    */
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (result > INT32_MAX / 10 || result == INT32_MAX && pop > 7) {
                return 0;
            }
            if (result < INT32_MIN / 10 || result == INT32_MIN && pop < -8) {
                return 0;
            }

            result = result * 10 + pop;
        }
        return result;
    }

    /**
     * @brief leetcode 9 palindrome number 回文数 easy
     *      给你一个整数x，如果x是一个回文整数，返回true，否则false
     * @example 输入x=121; true。
     *      输入x=-121; false
    */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x != 0 && x % 10 == 0) { // 最后一位是0，但x不是0
            return false;
        }
        // 只需要处理一半的数即可。结果相等的话说明是回文。奇数不影响。
        int result = 0;
        while (x > result) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return x == result || x == result / 10;
    }
    /**
     * @brief leetcode 13 roman-to-integer 罗马数字转整数 easy
     *      给定一个罗马数字，将其转换成整数，输入范围 1~3999 。
     * @note 罗马字母： I/1, V/5, X/10, L/50, C/100, D/500, M/1000。
     *      通常情况下，小的数在大的数右边。有六个特例：
     *      * I在V/X左边表示4/9
     *      * X在L/C左边表示40/90
     *      * C在D/M左边表示400/900
    */
    int romanToInt(string s) {
        int sum = 0;
        int pre_num = singalRomanToInt(s.at(0));
        for (int i = 1; i < s.length(); i++) {
            int cur_num = singalRomanToInt(s.at(i));
            if (pre_num < cur_num) {
                sum -= pre_num;
            } else {
                sum += pre_num;
            }
            pre_num = cur_num;
        }
        // 最后一个
        sum += pre_num;
        return sum;
    }
    // helper function
    int singalRomanToInt(char c) {
        switch (c)
        {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    }


    
};

