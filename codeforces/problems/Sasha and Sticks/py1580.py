n, k = map(int,input().split())
tours = n // k 
if tours % 2 == 0:
    print('no')
else:
    print('yes')
    