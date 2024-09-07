#include <iostream>
using namespace std;
// https://sunnywhy.com/problem/318
int main() {
    int n;
    cin >> n;
    int step = 0;
    while (n >= 2) {
        if (n % 2 == 0) {
            n = n >> 1;
            step++;
        } 
        else {
            n--;
            step++;
        }
    }
    cout << step << endl;
    return 0;
}