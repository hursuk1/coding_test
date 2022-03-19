from collections import deque
import copy
n, m = map(int, input().split())

virus = []
lab = []
no_safe = 0
for i in range(n):
    row = list(map(int, input().split()))
    for j, v in enumerate(row):
        if v == 2:
            virus.append((i, j))
            no_safe += 1
        elif v == 1:
            no_safe += 1
            
    lab.append(row)

def bfs(start, lab_copy, n, m):
    q = deque([])
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    q.append(start)
    cnt = 0
    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and lab_copy[nx][ny] == 0:
                lab_copy[nx][ny] = 2
                q.append((nx,ny))
                cnt += 1
    return cnt
safe = 0
for i in range(n*m):
    for j in range(i+1, n*m):
        for k in range(j+1, n*m):
            if lab[i//m][i%m] != 0 or lab[j//m][j%m] != 0 or lab[k//m][k%m] != 0:
                continue
            lab_copy = copy.deepcopy(lab)
            lab_copy[i//m][i%m] = 1
            lab_copy[j//m][j%m] = 1
            lab_copy[k//m][k%m] = 1

            no_safe_part = 3
            for v in virus:
                no_safe_part += bfs(v, lab_copy, n, m)

            safe = max(safe, n*m-no_safe-no_safe_part)
print(safe)