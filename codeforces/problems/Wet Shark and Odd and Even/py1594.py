n = int(input())
v = [int(i) for i in input().split()]
even = list(filter(lambda x: x % 2 == 0, v))
odd = list(filter(lambda x: x % 2 , v))
ans = sum(even) + sum(odd)

if len(odd) % 2 == 1:
    ans -= min(odd)
print(ans)
