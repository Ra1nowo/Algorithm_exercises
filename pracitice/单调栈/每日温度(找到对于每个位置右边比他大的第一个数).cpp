#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int temperatures[N];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temperatures[i];
    }
    int ans[N];
    memset(ans,0,sizeof(ans));
    stack<int> stk; // stk 用来记忆遍历过的数据
    for (int i = 0; i < n; ++i) {
        int curr = temperatures[i];
        while (!stk.empty() && temperatures[stk.top()] < curr) {
            int j = stk.top();
            stk.pop();
            ans[j] = i-j; 
        }
        stk.push(i); 
    }
    for (int k = 0; k < n; ++k) cout << ans[k] << " ";
    return 0;
}