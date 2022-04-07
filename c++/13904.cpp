#include <iostream>
#include <queue>

using namespace std;

// struct assingn
// {
//     int day, score;
//     assingn(int a, int b) : day(a), score(b) {}
// };

// struct cmp {
//     bool operator()(assingn a, assingn b) {
//         if (a.score == b.score) return a.day <= b.day;
//         return a.score <= b.score;
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;
//     priority_queue<assingn, vector<assingn>, cmp> assingns;
//     for (int i = 0; i < n; i++)
//     {
//         int d, s;
//         cin >> d >> s;
//         assingns.push(assingn(d,s));
//     }

//     return 0;
// }
#include <vector>
#include <algorithm>
#include <numeric>

bool cmp (pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> assingns;
    for (int i = 0; i < n; i++)
    {
        int d, s;
        cin >> d >> s;
        assingns.push_back({d,s});
    }
    sort(assingns.begin(), assingns.end(), cmp);
    vector<int> arr(1000, 0);

    while (!assingns.empty())
    {
        int day = assingns.back().first;
        int score = assingns.back().second;
        assingns.pop_back();
        for (int i = day-1; i >= 0; --i){
            if (score > arr[i])
            {
                arr[i] = score;
                break;
            }
        }
    }
    int result = accumulate(arr.begin(), arr.end(), 0);
    cout << result;
    return 0;
}