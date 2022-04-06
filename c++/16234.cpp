#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector <int>> countries;
int N, L, R;


int bfs(int &i, int &j, int &N, int &L, int &R, vector<vector <bool>> &visit) {
    deque<pair<int, int>> dq;
    int cnt = 1;
    dq.push_back({i,j});
    vector<pair<int, int>> index;
    int part_sum = countries[i][j];
    visit[i][j] = true;
    index.push_back({i,j});
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while (!dq.empty()) {
        int x = dq.front().first, y = dq.front().second;
        dq.pop_front();
        int nx, ny;
        for(int k = 0; k < 4; k++){
            nx = x + dx[k];
            ny = y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny]) {

                if (L <= abs(countries[nx][ny] - countries[x][y]) && abs(countries[nx][ny] - countries[x][y]) <= R) {
                    dq.push_back({nx, ny});
                    index.push_back({nx,ny});
                    cnt++;
                    part_sum += countries[nx][ny];
                    visit[nx][ny] = true;
                }
            }
        }

    }
    int people = part_sum / cnt;
    for (auto idx : index) {
        countries[idx.first][idx.second] = people;
    }
    return 1;

}

int main() {
    cin >> N >> L >> R;

    int country;
    
    for (int i=0; i<N; i++) {
        vector <int> temp;
        for (int j = 0; j < N; j++) {
            cin >> country;
            temp.push_back(country);
        }
        countries.push_back(temp);
    }

    int move_cnt = 0;
    
    while (1) {
        vector<vector <bool>> visit(N, vector <bool>(N, false));
        int bfs_cnt = 0;
        for (int i =0; i<N; i++){
            for(int j=0; j<N; j++) {
                if (!visit[i][j]) {
                    bfs_cnt += bfs(i,j,N,L,R, visit);
                }
            }
        }
        if (bfs_cnt == N*N) break;
        move_cnt++;
    }

    cout << move_cnt << endl; 

    return 0;
}

