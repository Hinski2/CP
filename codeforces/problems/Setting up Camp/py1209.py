t = int(input())
for _ in range(t):
    i, e, u = map(int, input().split())
    if e % 3 != 0 and e % 3 + u < 3:
        print(-1)
        continue
    ans = i + (e + u + 2) // 3
    print(ans)