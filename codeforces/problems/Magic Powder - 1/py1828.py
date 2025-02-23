n, k = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

l, r = 0, min(b) + k + 1
while l < r: 
    mid = (l + r + 1) // 2
    if sum([max(0, mid * ai - bi) for ai, bi in zip(a, b)]) <= k:
        l = mid 
    else:
        r = mid - 1
print(l)
             