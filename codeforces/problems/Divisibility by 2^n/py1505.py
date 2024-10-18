t = int(input())
ans = []

def how_many_two(x):
    two = 0
    while x % 2 == 0:
        two += 1
        x //= 2
    return two

for _ in range(t):
    n = int(input())
    v = list(map(int, input().split()))
    two = sum(list(map(how_many_two, v)))
    
    mult = sorted(list(map(how_many_two, range(1, n + 1))))[::-1]
    ile, idx = 0, 0
    while idx < n and two < n:
        two += mult[idx]
        idx += 1 
        ile += 1
    
    if two >= n:
        ans.append(ile)
    else:
        ans.append(-1)

print(*ans, sep='\n')
        
    