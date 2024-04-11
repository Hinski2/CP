def remove_div(v, y):
   return [x for x in v if y % x] 
   
   
n = int(input())
v = list(map(int, input().split()))
doub = [i for i in v if v.count(i) == 2]

x, y = 0, max(v)
if len(remove_div(v, y)) == 0:
    print(max(doub), y)
else:
    print(max(remove_div(v, y)), y)
    