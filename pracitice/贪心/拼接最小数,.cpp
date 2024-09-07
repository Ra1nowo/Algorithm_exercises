#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 10000;
string nums[MAXN];

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n, cmp);
    string result = "";
    for (int i = 0; i < n; i++) {
        result += nums[i]; 
    }
    while (result.length() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    cout << result << endl;
    return 0;
}