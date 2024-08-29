#include <iostream>
#include <algorithm>
using namespace std;
// https://sunnywhy.com/problem/595/solution/1251026237
int main() {
    string s;
    cin >> s;
    int i;
    sort(s.begin(),s.end());
    for (i = s.length()-1; i >= 0; --i) {
        if (s[i] % 2 == 0) {
            cout << s.substr(0,i) + s.substr(i+1) + s[i] << endl;
            break;
        }
    }
    if (i == -1) cout << -1 << endl;
    return 0;
}