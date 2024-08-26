#include <iostream>
using namespace std;
const int N = 1e5;
int n;
int a[100];
// 原题链接:https://sunnywhy.com/contest/112/problem/A
int FindEndOfFirstSegment(int n) {
    int l = -1, r = n;
    while (l+1<r) {
        int mid = (l + r) / 2;
        if (a[mid] >= a[mid+1]) r = mid;
        else l = mid; 
    } 
}

int FindBeginOfSecondSegment(int n) {
    int l = -1, r = n;
    while (l+1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= a[mid+1]) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = FindEndOfFirstSegment(n-3);
    int r = FindBeginOfSecondSegment(l+1,n-2);
    cout << r - l + 1 << endl;
    return 0;
}