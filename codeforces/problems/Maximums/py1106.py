n = int(input())
b = list(map(int, input().split()))

a = [b[0]]
maks = b[0]
for i in range(1, n):
    maks = max(maks, a[i - 1])
    a.append(maks + b[i])
    
a = ' '.join(map(str, a))
print(a)