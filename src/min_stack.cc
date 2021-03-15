#include <stack>
#include <algorithm>
#include <cstdint>

using namespace std;

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