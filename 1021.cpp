#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    deque<int> natural;
    for(int i = 1; i <= n; i++){
        natural.push_back(i);
    }
    int cnt = 0;
    for(int i : nums){
        int natural_size = natural.size();
        auto idx_ = find(natural.begin(), natural.end(), i);
        int idx = idx_ - natural.begin();
        if (idx == 0) {
            natural.pop_front();
        }
        else if (idx < natural_size - idx) {
            while (1) {
                int a = natural.front();
                natural.pop_front();
                if (a == i) {
                    break;
                }
                natural.push_back(a);
                cnt++;
            }
        }
        else {
            while (1) {
                int b = natural.back();
                natural.pop_back();
                if (b == i) {
                    cnt++;
                    break;
                }
                natural.push_front(b);
                cnt++;
            }
            
        }
    }
    cout << cnt << endl;
    return 0;
}