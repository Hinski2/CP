n = int(input())
w = map(int, input().split())
v = [0] * 110
i = 1
for u in w:
    v[i] = u
    i += 1
    
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    v[x - 1] += y - 1
    v[x + 1] += v[x] - y
    v[x] = 0

for i in range(1, n + 1):
    print(v[i])


    