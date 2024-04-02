n = int(input())
v, price = [], []
for i in range(n):
    a, b = map(int, input().split())
    v.append(a)
    price.append(b)
    
ans = 0
for i in range(1, n):
    price[i] = min(price[i - 1], price[i])

for i in range(n):
    ans += price[i] * v[i]

print(ans)