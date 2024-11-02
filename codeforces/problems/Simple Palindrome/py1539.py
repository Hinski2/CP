let = ['a', 'e', 'i', 'o', 'u']
t = int(input())
for _ in range(t):
    n = int(input())
    if n < 5:
        ans = let[:n]
    else:
        x = n // 5 
        ile = n % 5
        ans = []
        for i in range(5):
            ans += let[i] * (x + (ile > 0))
            ile -= 1 
    print(''.join(ans))
            
    