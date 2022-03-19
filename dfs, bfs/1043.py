from collections import deque

n, m = map(int, input().split())
story_truth = list(map(int, input().split()))
graph = [[] for _ in range(n+1)]

real_know_people = {}

if story_truth[0] != 0:
    for i in range(1, len(story_truth)):
        real_know_people[story_truth[i]] = 1

parties = []
for _ in range(m):
    party = list(map(int, input().split()))
    for i in range(1, party[0]):
        for j in range(i+1, len(party)):
            graph[party[i]].append(party[j])
            graph[party[j]].append(party[i])
    parties.append(party[1:])

def bfs(i):
    q = deque([])
    q.append(i)
    visited[i] = True
    while q:
        idx = q.popleft()
        for index in graph[idx]:
            if not visited[index]:
                q.append(index)
                visited[index] = True
                if index not in real_know_people:
                    real_know_people[index] = 1

visited = [False] * (n+1)
for real in story_truth[1:]:
    if not visited[real]:
        bfs(real)
cnt = 0
for par in parties:
    part_cnt = 0
    for p in par:
        if p in real_know_people:
            break
        else:
            part_cnt += 1
    if part_cnt == len(par):
        cnt += 1
print(cnt)