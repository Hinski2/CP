t = int(input())
for _ in range(t):
    n = int(input())
    b = input()
    
    a = ['1' for _ in range(n)]
    for i in range(1, n):
        if ord('1') + ord(b[i]) != ord(a[i - 1]) + ord(b[i - 1]): a[i] = '1'
        else: a[i] = '0' 
    
    print(*a, sep='')