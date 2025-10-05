#include <bits/stdc++.h>
using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> result;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].find(x) != string::npos) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    char x;
    cin >> x;

    vector<int> ans = findWordsContaining(words, x);

    for (int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}