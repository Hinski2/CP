s = input()
n = int(s[-2:]) % 4

ans = 1 + 2 ** n + 3 ** n + 4 ** n
print(ans % 5)
