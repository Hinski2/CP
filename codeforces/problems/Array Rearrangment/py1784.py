t = int(input())
for i in range(t):
    if i: input()
    
    n, x = map(int, input().split())
    a = sorted(list(map(int, input().split())), reverse=True)
    b = sorted(list(map(int, input().split())))
    if all(a[i] + b[i] <= x for i in range(n)):
        print('Yes')
    else:
        print('No')