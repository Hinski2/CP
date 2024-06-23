t = int(input())
for _ in range(t):
    n, f, k = map(int, input().split())
    f, k = f - 1, k - 1
    v = list(map(int, input().split()))
    f = v[f]
    v.sort(reverse=True)
    if v[k] > f: print("NO")
    elif v[k] < f: print("YES")
    else: print("YES" if k == n - 1 or v[k + 1] < f else "maybe")
    

    