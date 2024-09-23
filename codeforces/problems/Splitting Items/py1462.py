t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    v = list(sorted(map(int, input().split())))[::-1]
    
    for i in range(1, n, 2):
        if v[i - 1] != v[i] and k:
            x = min(k, v[i - 1] - v[i])
            k -= x 
            v[i] += x
    
    A, B = sum(v[::2]), sum(v[1::2])
    print(A - B)