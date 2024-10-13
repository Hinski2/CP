n, k = map(int, input().split())
v = list(input())

if n == 1 and k:
    print(0)
    exit(0)

changed = 0
for i in range(n):
    if changed == k:
        break
    if v[i] != ('0' if i else '1'):
        v[i] = '0' if i else '1'
        changed += 1
    if changed == k:
        break

print(''.join(v))
