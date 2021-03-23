/**
 * @file 整数相关
 *       7整数反转, 9回文数，13罗马数字转整数，66加一，67二进制求和，326三的幂
 *       191位1的个数，204计数质数
*/
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

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
    int reverseInteger(int x) {
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

    /**
     * @brief leetcode 66 plus one 加一 easy
     *      给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一
     *      最高位数字存放在数组的首位，数组中每个元素只存储单个数字。
     *      可以假设除了0之外，这个整数不会以0开头。
     * @example 输入digits = [1,2,3], 输出 [1,2,4]
    */
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            // 只有 9 加一才会产生进位。
            if (digits[i] != 0) { // 某一位没产生进位，说明已经加完
                return digits;
            }
        }
        // 一直进位到了最高位
        digits.insert(digits.begin(), 1);
        return digits;
    }

    /**
     * @brief leetcode 67 add-binary 二进制求和 easy
     *      给定两个二进制字符串，返回它们的和(用二进制表示)
     *      输入为非空，只包含1和0。
     * @example a = "11", b = "1", 输出 "100"
     *          a = "1010", b = "1011"，输出 "10101"
    */
    string addBinary(string a, string b) {
        string result;

        // 先反转并填充0到相同长度。
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int m = max(a.length(), b.length());
        int n = min(a.length(), b.length());
        // maybe m equals to n
        string zeros(m - n, '0');
        if (a.length() > b.length()) {
            b.append(zeros);
        } else if (a.length() < b.length()) {
            a.append(zeros);
        }

        // 挨个加
        int sum   = 0; // 保存每次加法的实际结果
        int bit   = 0; // 保存每次加法的无进位结果
        int carry = 0; // 保存每次加法的进位
        for (int i = 0; i < m; i++) {
            sum = a[i] - '0' + b[i] - '0' + carry; // 得到实际整数结果
            bit = sum % 2;    // 获得加法结果
            carry = bit / 2;  // 获得加法进位

            result.push_back(bit + '0');
        }
        // 最高位有进位
        if (carry == 1) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());
        return result;
    }

    /**
     * @brief leetcode 326 power of three 3的幂 easy
     *        判断一个整数是否是3的幂
    */
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        // 一直除以3，只要有一次余数不为0，那说明不是3的幂。
        while (n != 1) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return true;
    }

    /**
     * @brief leetcode 191 number-of-1-bits 位1的个数 easy
    */
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }


    /**
     * @brief leetcode 204 count-primes 计数质数 easy
     *        统计所有小于非负整数n的质数的数量
     * @note 埃氏筛。
     *       如果x是质数，那么，2x, 3x,4x...都不是质数。
     *       设 isPrime[i] 表示数i是不是质数，如果i是，那么，将其所有倍数，
     *       i除外，都标记为0.
     *       优化：对于一个质数x，从2x开始标记其实是冗余的，可以直接从x*x开始。
     *       因为2x,3x这些数一定在x之前就被标记过了，如2的倍数，3的倍数
    */
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                ans++;
                if ((long long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

