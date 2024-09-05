#include <iostream>
using namespace std;
// https://leetcode.cn/problems/clear-digits/
int main() {
    string s;
    cin >> s;
    string res = "";
    for (char c:s) {
        if (isdigit(c)) {
            res.pop_back();
        }
        else {
            res += c;
        }
    }
    cout << res << endl;
    return 0;
}