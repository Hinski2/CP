n = int(input())
v = sorted([[sum([int(i) for i in input().split()]), i + 1] for i in range(n)], key=lambda x: (-x[0], x[1]))
place = 0
for i in range(n):
    if v[i][1] == 1: place = i + 1
print(place)
