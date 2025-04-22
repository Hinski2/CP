t = int(input())
for _ in range(t):
    n = int(input())
    vs = [int(i) for i in input().split()]
    
    if n & 1 or min(vs[::2]) > min(vs[1::2]):
        print("Mike")
    elif min(vs[::2]) == min(vs[1::2]) and vs[::2].index(min(vs[::2])) * 2 > vs[1::2].index(min(vs[1::2])) * 2 + 1:
        print("Mike")
    else:
        print("Joe")
        
    