t = int(input())
for _ in range(t):
    v = [int(i) for i in input().split()]
    print(0 if (v[0] + v[2] - 2*v[1]) % 3 == 0 else 1)