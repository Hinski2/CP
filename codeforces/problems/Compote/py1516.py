a = int(input())
b = int(input())
c = int(input())

x = min(a, b // 2, c // 4)
y = min(a, x) + min(b, x * 2) + min(c, x * 4)

print(y)