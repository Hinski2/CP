t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    v = [int(i) for i in input().split()]
    time = 0
    for i in range(n):
        time += v[i] - time % v[i]
    ans.append(time)
print(*ans, sep='\n')
    