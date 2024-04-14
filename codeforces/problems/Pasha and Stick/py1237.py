n = int(input())
print(0 if n == 1 or n & 1 else (n // 2 - 1) // 2)
