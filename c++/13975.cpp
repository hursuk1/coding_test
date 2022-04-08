#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t, k;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        priority_queue<long long, vector<long long>, greater<long long>> file;
        for (int j = 0; j < k; j++)
        {
            long long file_size;
            cin >> file_size;
            file.push(file_size);
        }
        long long min_cost = 0;
        while (1 != file.size())
        {
            long long a, b;
            a = file.top();
            file.pop();
            b = file.top();
            file.pop();
            min_cost += a+b; 
            file.push(a+b);
        }
        cout << min_cost << endl;
    }

    return 0;
}