/**
 * @file 整数相关
 * 7整数反转, 9回文数
*/
#include <cstdint>

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

};

