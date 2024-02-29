t = int(input())
for _ in range(t):
    n = int(input())
    v = map(int, input().split())
    v = [abs(i) for i in v]
    print(sum(v))