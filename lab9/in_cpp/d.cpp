#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Преобразование строки к нижнему регистру
string to_lower(const string& s) {
    string res = s;
    for (char &c : res) {
        c = tolower(c);
    }
    return res;
}

// Поиск наибольшего префикса s2, который является суффиксом s1
int max_prefix_suffix_kmp(const string& P, const string& city) {
    // Нам нужен префикс city, совпадающий с суффиксом P
    string s = city + '#' + P;
    int n = s.length();
    vector<int> pi(n, 0);
    
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    
    // Значение префикс-функции в самом конце и есть длина искомого совпадения
    return pi[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string P;
    if (!(cin >> P)) return 0;

    int n;
    cin >> n;

    vector<string> original_cities(n);
    vector<int> match_lengths(n);

    string P_lower = to_lower(P);

    int max_len = -1;

    for (int i = 0; i < n; i++) {
        cin >> original_cities[i];
        string city_lower = to_lower(original_cities[i]);

        int len = max_prefix_suffix_kmp(P_lower, city_lower);
        match_lengths[i] = len;

        if (len > max_len) {
            max_len = len;
        }
    }
    if (max_len == 0) {cout << 0; return 0;}

    // Подсчитываем результат
    vector<string> result;
    for (int i = 0; i < n; i++) {
        if (match_lengths[i] == max_len) {
            result.push_back(original_cities[i]);
        }
    }

    cout << result.size() << "\n";
    for (const string& city : result) {
        cout << city << "\n";
    }

    return 0;
}