def div3(n, d) -> bool:
    return n >= 3 or d % 3 == 0

def div5(n, d) -> bool:
    return d == 5

def div7(n, d) -> bool:
    return n >= 3 or d == 7

def div9(n, d) -> bool:
    if n >= 6 or d % 9 == 0: return 1
    return n >= 3 and d % 3 == 0

t = int(input())
for i in range(t):
    n, d = map(int, input().split())
    ans = [1]
    if div3(n, d): ans.append(3)
    if div5(n, d): ans.append(5)
    if div7(n, d): ans.append(7)
    if div9(n, d): ans.append(9)
    print(*ans)
    