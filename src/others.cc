/**
 * 69x的平方根，70爬楼梯
*/
#include <vector>
#include <string>

using namespace std;

class OtherSolution {
public:
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




























