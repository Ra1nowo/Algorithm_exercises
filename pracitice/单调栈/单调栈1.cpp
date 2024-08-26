#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 7e5 + 10;
int a[N],l[N],r[N];
stack<int> stk1,stk2;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l[i] = r[i] = -1;
    }
    // 找右边比他大的第一个数
    for (int i = 1; i <= n; ++i) {
        int h = a[i];
        while (!stk1.empty() && h > a[stk1.top()]) {
            r[stk1.top()] = i;
            stk1.pop();
        }
        stk1.push(i);
    }
    // 找左边比他大的第一个数
    for (int j = n; j >= 1; --j) {
        int h = a[j];
        while (!stk2.empty() && h > a[stk2.top()]) {
            l[stk2.top()] = j;
            stk2.pop();
        }        
        stk2.push(j);
    }
    for (int i = 1; i <= n; ++i) {
        cout << l[i] << " ";
    }
    cout << endl;
    for (int j = 1; j <= n; ++j) {
        cout << r[j] << " ";
    }
    return 0;
}