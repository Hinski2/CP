# t - munuset for owen to bake k carrot cakes
# need n cakes
# d minutes to buid the oven
n, t, k, d = map(int, input().split())
if d + t < (n + k - 1) // k * t:
    print('YES')
else:
    print('NO')

