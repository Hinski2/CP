t = int(input())
while t:
    t -= 1

    mini, maxi = 1, int(1e9)
    n = int(input())
    ban = []
    for i in range(n):
        a, b = map(int, input().split())
        if a == 1:
            mini = max(mini, b)
        elif a == 2:
            maxi = min(maxi, b)
        else:
            ban.append(b)
    
    print(max(maxi - mini + 1 - sum(1 for x in ban if mini <= x <= maxi), 0))


        