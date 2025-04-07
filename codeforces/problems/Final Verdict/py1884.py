t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = [int(i) for i in input().split()]
    if sum(v) % n == 0 and sum(v) // n == k:
        print("YES")
    else:
        print("NO")