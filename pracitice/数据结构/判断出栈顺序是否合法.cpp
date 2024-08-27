#include <iostream>
#include <stack>
using namespace std;

const int N = 101;
int a[N];
stack<int> stk;
bool isValid = true;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > m) {
            for (int j = m+1; j <= a[i]; ++j) stk.push(j);
            m = a[i];
        }
        if (stk.top() != a[i]) {
            isValid = false;
            break;
        }
        else stk.pop();
    }
    string res = isValid?"Yes":"No";
    cout << res << endl;
    return 0;
}
