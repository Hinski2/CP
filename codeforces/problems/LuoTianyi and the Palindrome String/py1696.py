t = int(input())
for _ in range(t):
    s = [u for u in input()]
    if all([u == s[0] for u in s]):
        print(-1)
    else:
        print(len(s) - 1)