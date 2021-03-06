/**
 * @file 栈相关问题
 *       20有效的括号，150逆波兰表达式求值，155最小栈
*/
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class StackSolution {
public:
    /**
     * @brief leetcode 20 valid-parentheses 有效的括号 easy
     * 给定一个只包括"{}()[]"的字符串s，判断字符串是否有效
    */
    bool isValid(string s) {
        int len = s.length();

        if (len % 2 == 1) { // 奇数肯定不行
            return false;
        }

        auto paires = unordered_map<char, char> {
            {')', '('}, {']', '['}, {'}', '{'}
        };

        auto workstack = stack<char>();
        for (int i = 0; i < len; i++) {
            char ch = s.at(i);
            if (paires.find(ch) != paires.end()) { // 找到了右括号
                if (workstack.empty() || workstack.top() != paires.at(ch)) {
                    return false; // 找到右括号的情况下如果栈空或栈顶不匹配，则假
                }
                workstack.pop();
            } else { // 左括号
                workstack.push(ch);
            }
        }
        return workstack.empty();
    }

    /**
     * @brief leetcode 150 evaluate-reverse-polish-notation 求逆波兰表达式 mideum
     * @note 逆波兰表达式：也称后缀表达式。没有括号，运算符总是在它相关的操作数之后。
     * @example Input: tokens = ["2", "1", "+", "3", "*"], Output: 9
    */
    int evalRPN(vector<string>& tokens) {
        auto stk = stack<int>();
        for (const string& s : tokens) {
            if (!isOperator(s)) {
                stk.push(atoi(s.c_str()));
            } else { // 遇到操作符，弹出两个数，运算后再入栈
                int r = stk.top();  stk.pop();  // 右操作符首先弹出
                int l = stk.top();  stk.pop();

                switch (s[0])
                {
                case '+': stk.push(l + r); break;
                case '-': stk.push(l - r); break;
                case '*': stk.push(l * r); break;
                case '/': stk.push(l / r); break;
                default: break;
                }
            }
        }
        return stk.top();
    }
    // hlp
    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
};

/**
 * @brief leetcode 155 min-stack 最小栈 easy
 *        设计一个栈，支持push, pop, top操作，并能在常数时间检索到最小元素的栈
*/
class MinStack {
private:
    /** initialize your data structure here. */
    stack<int> x_stack;
    stack<int> min_stack;
public:

    MinStack() {
        min_stack.push(INT32_MAX);
    }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(x, min_stack.top()));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

