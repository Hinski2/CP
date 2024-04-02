def is_sorted(v):
    for i in range(1, len(v)):
        if v[i - 1] > v[i]: return False
    
    return True

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(map(int, input().split()))
    if k == 1 and not is_sorted(v):
        print("NO")
    else:
        print("YES")