/**
 * 字符串相关
 * 14最长公共前缀
*/
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

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
};