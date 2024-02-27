def valid(x, n):
    return x >= 0 and x < n

t = int(input())
for _ in range(t):
    n = int(input())
    ai = input()
    a = [int(char) for char in ai]

    bi = input()
    b = [int(char) for char in bi]
    ablock = [False for i in range(n)]

    ans = 0
    for i in range(n):
        if b[i] and not a[i]: ans += 1
        elif b[i] and valid(i-1, n) and not ablock[i - 1] and a[i-1]: ans += 1
        elif b[i] and valid(i+1, n) and a[i + 1]:
            ans += 1
            ablock[i + 1] = True
    print(ans)
    