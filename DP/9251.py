string_A = list(input())
string_B = list(input())

LCS = [[0 for _ in range(len(string_B)+1)] for _ in range(len(string_A)+1)]

for i in range(1, len(string_A)+1):
    for j in range(1, len(string_B)+1):
        if i == 0 or j == 0:  # 마진 설정
            LCS[i][j] = 0
        elif string_A[i-1] == string_B[j-1]:
            LCS[i][j] = LCS[i - 1][j - 1] + 1
        else:
            LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])
print(LCS[len(string_A)][len(string_B)])
# b_idx=0
# cnt = 0
# for i in range(len(a)):
#     for idx in range(b_idx, len(b)):
#         if a[i] == b[idx]:
#             b_idx = idx
#             cnt += 1
#             break
# print(cnt)