/**
 * 贪心算法 Greedy
 * 135分发糖果，455分发饼干，
*/
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class GreedySolution {
public:
    /**
     * @brief leetcode 135 candy 分发糖果 hard
     *        老师想给孩子们分发糖果，有N个孩子站成一条直线，每个孩子预先有一个分数。
     *        你需要按照以下要求，给这些孩子们分发糖果。
     *        + 每个孩子至少分到一个糖果
     *        + 评分更高的孩子必须比他两侧的的邻位孩子获得更多的糖果
     * @example Input: [1,0,2] Output: 5 explain: 分别获得(2,1,2)
    */
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if (len < 2) {
            return len;
        }

        auto candies = vector<int>(len, 1);
        // 先从左到右，保证这个方向上每个人都满足糖果数量多少的相对关系
        for (int left = 0; left < len - 1; left++) {
            int right = left + 1; // 追求最高可读性
            if (ratings[right] > ratings[left]) { // 右边人分数更高
                candies[right] = candies[left] + 1;
            }
        }
        // 再从右到左，保证这个方向上每个人都满足...
        for (int right = len - 1; right > 0; right--) {
            int left = right - 1;
            if (ratings[left] > ratings[right]) {
                candies[left] = max(candies[left], candies[right] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }

    /**
     * @brief leetcode 455 assign-cookies 分发饼干 easy
     *        有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干有一个大小。
     *        每个孩子只能吃最多一块饼干，且只有饼干的大小大于等于孩子的饥饿度，
     *        这个孩子才能吃饱。求解最多有多少个孩子可以吃饱。
     * @example Input:饥饿度[1, 2], 饼干[1, 2, 3]  Output: 2。
     *          可以给这两个孩子[1,2], [1,3], [2,3]三种里的任一种。
     * @solution 因为饥饿度最小的孩子最容易吃饱，所以我们先考虑这个孩子。为了尽可能给更多
     *           的孩子，应该把大于等于这个孩子的饥饿度且当前大小最小的饼干给这个孩子。
     *           接下来重复，直到没有满足条件的饼干。
    */
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());

        // 策略：对每一个孩子，在当前剩余的饼干中找最小的那块，找到了就再为下一个孩子找。
        int child = 0, curr_cookie = 0;
        while (child < children.size() && curr_cookie < cookies.size()) {
            if (children[child] <= cookies[curr_cookie]) {
                // 当前孩子已吃饱，为下一个孩子找饼干。
                child++;
            }
            curr_cookie++;
        }

        return child;
    }
};
