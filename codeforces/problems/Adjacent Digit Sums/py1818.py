t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if (a + 1 - b) % 9 == 0 and a + 1 - b >= 0:
        print('Yes')
    else:
        print('No') 