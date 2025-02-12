t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    ans = a + 2*b + 3*c 
    print(ans % 2)