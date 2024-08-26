#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

const int N = 100;
char sq[N];
stack<char> st;
unordered_map<char, char> match = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> sq[i];
    
    for (char ch : sq) {
        if (match.find(ch) != match.end()) {
            // 如果是左括号，压入栈
            st.push(ch);
        } else {
            // 如果是右括号，检查栈是否为空或是否匹配
            if (st.empty() || match[st.top()] != ch) {
                cout << "false" << endl;
                return 0;
            }
            // 匹配成功，弹出栈顶元素
            st.pop();
        }
    }
    
    // 检查栈是否为空
    if (st.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
