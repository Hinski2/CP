import string
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    dic = {i: 0 for i in string.ascii_lowercase}
    for u in s:
        dic[u] += 1
    
    odd = 0
    for u in dic:
        odd += dic[u] & 1

    if odd - 1 > k: print("NO")
    else: print("YES")
