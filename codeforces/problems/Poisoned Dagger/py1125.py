def check(v, n, hp):
    damage = 0
    for i in range(0, len(v) - 1):
        damage += min(v[i + 1] - v[i], n)
        
    damage += n
    return damage >= hp

t = int(input())
for _ in range(t):
    n, hp = map(int, input().split())
    v = list(map(int, input().split()))
    l, r = 0, int(1e18)
    while l < r:
        mid = (l + r) // 2
        if check(v, mid, hp): r = mid
        else: l = mid + 1
    
    print(l)