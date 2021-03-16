/**
 * 69x的平方根，70爬楼梯，121买卖股票的最佳时机
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

    /**
     * @brief leetcode 121 best-time-to-buy-and-sell-stock 买卖股票的最佳时机 easy
     *        给定一个数组prices, 它的第i个元素表示一支给定股票第i天的价格。
     *        只能选择某一天买入，并在之后某一天卖出，计算你能获取的最大利润。
     *        每天的价格在 0~10000之间。
     * @note 设在第x天卖出。那么，这一天能获得的最大利润就是 (prices[x] - 之前最低价)。
     *       所以，对每一天x，都保存当前的历史最低价，并计算利润，一次遍历即可。
    */
    int maxProfit(vector<int>& prices) {
        int lowest = 1e5;
        int maxProfit = 0;
        for (const int& p : prices) {
            lowest = min(lowest, p); // 更新最低价格
            maxProfit = max(maxProfit, p - lowest); // 这一天能获得的最大利润
        }
        return maxProfit;
    }
};




























