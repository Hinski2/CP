ans = 0
ok_dig = [2,4,7]
def ok(x):
    while(x):
        if not x % 10 in ok_dig: return 0
        x //= 10
    return 1

print(sum([ok(i) for i in range(1000, 10000, 2)]))
    
    