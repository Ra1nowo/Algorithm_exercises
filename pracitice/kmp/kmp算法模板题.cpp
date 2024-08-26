#include <iostream>
using namespace std;
// 原题链接:https://sunnywhy.com/problem/437
const int N = 1e4 + 10;
string pattern, text;
int ne[N];

void getNext() {
    int j = -1;
    ne[0] = -1;
    for (int i = 1; i < pattern.size(); ++i) {
        while (j != -1 && pattern[i] != pattern[j+1]) {
            j = ne[j];
        }
        if (pattern[i] == pattern[j+1]) j++;
        ne[i] = j;
    }
}

bool kmp() {
    getNext();
    int j = -1;
    for (int i = 0; i < text.size(); ++i) {
        while (j != -1 && text[i] != pattern[j+1]) {
            j = ne[j];
        }
        if (text[i] == pattern[j+1]) j++;
        if (j == pattern.size() - 1) return true;
    }
    return false;
}

int main() {
    cin >> text >> pattern;
    cout << (kmp()?"Yes":"No");
    return 0;
}