#include <iostream>
#include <string>

using namespace std;

int main() {
    string number;
    int n, k;
    cin >> n >> k;
    cin >> number;
    string greater_num;
    greater_num.push_back(number[0]);
    for (int i = 1; i < n; i++){
        while (k != 0 && !greater_num.empty() && greater_num.back() < number[i]) {
            greater_num.pop_back();
            k--;
        }
        greater_num.push_back(number[i]);
    }
    while (k--) {
        greater_num.pop_back();
    }

    cout << greater_num << endl;

    return 0;
}