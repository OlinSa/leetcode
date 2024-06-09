#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        /**
         * 使用一个栈，存入索引。表示最后一个没有被匹配上的坐标
         */
        std::stack<int> stk;
        int maxans = 0;
        stk.push(-1);
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '('){
                stk.push(i);
            }else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }else {
                    maxans = std::max(i- stk.top(), maxans);
                }
            }
        }
        return maxans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout<<s.longestValidParentheses("(()")<<std::endl;
    std::cout<<s.longestValidParentheses(")()())")<<std::endl;
    std::cout<<s.longestValidParentheses("")<<std::endl;
    std::cout<<s.longestValidParentheses("(())")<<std::endl;
    return 0;
}