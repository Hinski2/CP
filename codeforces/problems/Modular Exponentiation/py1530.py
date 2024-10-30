n = int(input())
m = int(input())

x = 1; ile = 0
while x * 2 <= 1e9 and ile < n: 
    x *= 2 
    ile += 1 

if x > m: 
    print(m)
else:
    print(m % x)
    