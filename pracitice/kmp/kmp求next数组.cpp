#include <iostream>
using namespace std;
// 原题链接:https://sunnywhy.com/problem/435/solution/2105497614
const int N = 100000 + 1;
string s;
int ne[N];

// 计算 next 数组
void getNext(int len) {
    ne[0] = -1;
    int j = -1;
    for (int i = 1; i < len; ++i) {
        while (j != -1 && s[i] != s[j+1]) j = ne[j];
        if (s[i] == s[j+1]) j++;
        ne[i] = j;
    }
}

int main() {
    cin >> s;
    int len = s.size();
    getNext(len);
    for (int i = 0; i < len; ++i) {
        if (i < len-1) {
            cout << ne[i]+1;
            cout << " ";
        }
        else {
            cout << ne[i]+1;
            cout << endl;
        }
    }
    return 0;
}