t = int(input())
for _ in range(t):
    n, h = map(int, input().split())
    v = list(map(int, input().split()))
    
    a = [max(v)]
    v.remove(a[0])
    a += [max(v)]
    
    if h % sum(a) == 0: ans = 2 * (h // sum(a))
    elif h % sum(a) <= a[0]: ans = 2 * (h // sum(a)) + 1
    else: ans = 2 * (h // sum(a)) + 2
    
    print(ans)
    
    