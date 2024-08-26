#include <iostream>
using namespace std;

const int N = 50;
typedef struct {
    int a[N];
    int length;
}seqlist;
// 1 3 4 2 6->  1 3 3 4 2 6
void listInsert(int idx, int e, seqlist &l) {
    for (int i = l.length; i >= idx; --i) l.a[i] = l.a[i-1];
    l.a[idx-1] = e;
    l.length++;
}

void listDelete(int idx, seqlist &l) {
    if (idx < 1 || idx > l.length+1) return;
    for (int i = idx; i < l.length; ++i) l.a[i-1] = l.a[i];
    l.length--;
}

int locateElem(int e ,seqlist l) {
    for (int i = 0; i < l.length; ++i) {
        if (l.a[i] == e) return i + 1;
    }
    return -1;
}

void reverse(seqlist &l) {
    int left = 0, right = l.length - 1;
    while (left < right) {
        int temp = l.a[left];
        l.a[left] = l.a[right];
        l.a[right] = temp;
        left++;
        right--;
    }
}
void delval(int e, seqlist &l) {
    int s = 0;
    for (int f = 0; f < l.length; ++f) {
        if (l.a[f] != e) l.a[s++] = l.a[f];
    }
    l.length = s;
}

void merge(seqlist l1, seqlist l2, seqlist &c) {
    if (l1.length + l2.length > c.length) return;  // 确保目标表足够大
    int p1 = 0, p2 = 0, k = 0;
    while (p1 < l1.length && p2 < l2.length) {
        c.a[k++] = l1.a[p1] < l2.a[p2] ? l1.a[p1++] : l2.a[p2++];
    }
    while (p1 < l1.length) {
        c.a[k++] = l1.a[p1++];
    }
    while (p2 < l2.length) {  // 修正这里的条件
        c.a[k++] = l2.a[p2++];
    }
    c.length = k;  // 设置合并后表的长度
}

int main() {
    seqlist l1,l2,c;
    int length;
    cin >> l1.length >> l2.length >> l2.length;
    for (int i = 0; i < l1.length; ++i) cin >> l1.a[i];
    for (int i = 0; i < l2.length; ++i) cin >> l2.a[i];
    merge(l1,l2,c);
    for (int i = 0; i < c.length; ++i) cout << c.a[i] << " ";

}