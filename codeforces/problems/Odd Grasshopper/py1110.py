t = int(input())

lam = [
    lambda x: 0,
    lambda x: x,
    lambda x: -1,
    lambda x: -x - 1
]

for _ in range(t):
    n, ile = map(int, input().split())
    
    d = lam[ile % 4](ile)
    print(n - d if n % 2 == 0 else n + d)