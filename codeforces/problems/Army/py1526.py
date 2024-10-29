n = int(input())
v = [0] + list(map(int, input().split()))
a, b = map(int, input().split())
print(sum(v[a: b]))