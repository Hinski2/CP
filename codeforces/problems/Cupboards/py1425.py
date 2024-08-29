n = int(input())
l, r = 0, 0
for _ in range(n):
    l, r = map(int, input().split())
    
print(min(l, n - l) + min(r, n - r))