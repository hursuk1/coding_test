#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return (a.second) < (b.second);
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> books(n, 1);
        vector<pair<int, int>> want;
        for(int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;
            want.push_back({a,b});
        }
        sort(want.begin(), want.end(), cmp);
        int cnt = 0;
        for(int k = 0; k < want.size(); k++)
        {
            for (int l = want[k].first; l <= want[k].second; l++)
            {
                if (books[l-1] == 1) {
                    books[l-1] = 0;
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}