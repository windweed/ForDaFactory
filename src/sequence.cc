/**
 * @file 连续内存问题。包含数组和字符串。
 * 88合并两个有序数组
*/

#include <vector>

using namespace std;

class SequenceSolution {
public:
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
};

