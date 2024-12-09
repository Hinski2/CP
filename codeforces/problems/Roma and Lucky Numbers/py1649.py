def no(x):
    no = 0
    while x:
        if x % 10 == 4 or x % 10 == 7: no += 1
        x //= 10
    return no 

n, k = map(int, input().split())
v = [int(i) for i in input().split()]
print(sum([no(i) <= k for i in v]))