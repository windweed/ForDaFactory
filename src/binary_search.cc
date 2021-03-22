/**
 * @file Binary Search
 *       50:powx-n
*/

class BinSearchSolution {
public:
    /**
     * @brief 50: Pow(x, n) easy
     *        Implement `pow(x, n)`, which calculates `x` raised to the power n
     * @example ① Input: x=2.00000, n = 10; Output: 1024.0000
     *          ② Input: x=2.1, n=3; Output: 9.261
     * @solve: 要求 x^n, 先求出 x^(n/2), 若n为偶数，则x^n 等于 x^(n/2)的平方。
     *         若为奇数，则等于 x^(n/2) * x。
    */
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0
               ? quickPow(x, N)
               : 1.0 / quickPow(x, -N);
    }
    // helper funtion
    double quickPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double y = quickPow(x, n / 2);
        return n % 2 == 0
               ? y * y
               : y * y * x;
    }

};