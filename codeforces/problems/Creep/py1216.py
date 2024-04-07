t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    for i in range(min(a, b)):
        print("01", end="")
    for i in range(abs(a - b)):
        print('1' if a < b else '0', end="")
    print()
    