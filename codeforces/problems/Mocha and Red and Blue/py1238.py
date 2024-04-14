def prev(v):
    for i in range(len(v) - 1, -1, -1):
        if v[i] != '?': return v[i]
    return '?'
def next(v):
    for i in range(len(v)):
        if v[i] != '?': return v[i]
    return '?'

t = int(input())
for _ in range(t):
    n = int(input())
    v = list(input())
    for i in range(n):
        for j in range(n):
            if v[j] == '?' and j and v[j - 1] != '?':
                v[j] = 'B' if v[j - 1] == 'R' else 'R'
                break
            elif v[j] == '?' and j + 1 < n and v[j + 1] != '?':
                v[j] = 'B' if v[j + 1] == 'R' else 'R'
                break
            if j + 1 == n and v[j] == '?':
                v[j] = 'B'
    print(*v, sep='')

