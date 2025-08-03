n, m = map(int, input().split())
v = [input() for _ in range(n)]

mapa = {}
for u in v:
    if u in mapa or u[::-1] in mapa:
        if u in mapa: mapa[u] += 1
        else: mapa[u[::-1]] += 1
    else:
        mapa[u] = 1
        
pal = ""
for k, v in mapa.items():
    if v % 2 and len(k) > len(pal) and k == k[::-1]:
        pal = k
        
a = ""
for k, v in mapa.items():
    a += k * (v // 2)
    
ans = a + pal + a[::-1]
print(len(ans))
print(ans)
        