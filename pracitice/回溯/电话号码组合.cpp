#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const unordered_map<char, string> match = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void dfs(const string& digits, string& path, vector<string>& res, int idx) {
    if (idx == digits.length()) {
        res.push_back(path);
        return;
    }
    string str = match.at(digits[idx]);
    for (char c : str) {
        path.push_back(c);
        dfs(digits, path, res, idx + 1);
        path.pop_back();
    }
}

int main() {
    string digits;
    cin >> digits;

    vector<string> res;
    string path;
    dfs(digits, path, res, 0);

    for (const string& s : res) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
