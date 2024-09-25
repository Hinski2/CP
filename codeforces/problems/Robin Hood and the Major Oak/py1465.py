t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    
    odd = ["NO", "NO", "YES", "YES"]
    even = ["YES", "NO", "NO", "YES"]
    
    if (n - k + 1) % 2 == 1:
        print(odd[(k - 1) % 4])
    else:
        print(even[(k - 1) % 4])
    