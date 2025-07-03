t = int(input())
for _ in range(t):
    n, j, k = map(int, input().split())
    v = list(map(int, input().split()))
    j_val = v[j - 1]
    
    v = sorted(v)
    if k == 1 and v[n - 1] == j_val or k > 1:
        print("YES")
    else:
        print("NO")
