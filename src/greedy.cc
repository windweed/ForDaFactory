/**
 * 贪心算法 Greedy
 * 455分发饼干，
*/
#include <vector>

using namespace std;

class GreedySolution {
public:
    /**
     * @brief leetcode 455 assign-cookies 分发饼干 easy
     *        有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干有一个大小。
     *        每个孩子只能吃最多一块饼干，且只有饼干的大小大于等于孩子的饥饿度，这个孩子才能吃饱。
     *        求解最多有多少个孩子可以吃饱。
     * @example Input:饥饿度[1, 2], 饼干[1, 2, 3]  Output: 2。
     *          可以给这两个孩子[1,2], [1,3], [2,3]三种里的任一种。
     * @solution 因为饥饿度最小的孩子最容易吃饱，所以我们先考虑这个孩子。为了尽可能给更多的孩子，应该把
     *           大于等于这个孩子的饥饿度且当前大小最小的饼干给这个孩子。接下来重复，直到没有满足条件的饼干。
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
