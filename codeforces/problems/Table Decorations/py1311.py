v = list(map(int, input().split()))
if max(v) > 2 * (sum(v) - max(v)): 
    print(sum(v) - max(v))
else: 
    print(sum(v) // 3)