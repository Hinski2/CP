v = map(int, input().split())
v = sorted(v)
if v[0] + v[3] == v[1] + v[2] or sum(v[:3]) == v[3]:
    print("YES")
else:
    print("NO")
