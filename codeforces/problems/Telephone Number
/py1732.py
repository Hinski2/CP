t = int(input())
for _ in range(t): 
    n = int(input())
    x = list(input())
    if(n < 11):
        print("NO")
        continue
    idx = n - 11
    while(idx >= 0):
        if x[idx] == '8':
            print("YES")
            break
        idx -= 1
    else:
        print("NO")
