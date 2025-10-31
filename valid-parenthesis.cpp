class Solution {
public:
    bool isValid(string s) {
        bool isValid(string s) {
        if (s.empty() || s.length() < 2) {
            return false;
        }
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c); 
            } else {
                if (stack.empty()) {
                    return false;
                }
                char last = stack.top();
                stack.pop();
                if (c == ')' && last != '(') { 
                    return false;
                }
                if (c == ']' && last != '[') {
                    return false;
                }
                if (c == '}' && last != '{') {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};