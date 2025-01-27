m, n = map(int, input().split())
idx = 1
while n >= idx:
    n -= idx 
    idx += 1
    if idx > m:
        idx = 1
        
print(n)