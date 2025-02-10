t = int(input())
for _ in range(t):
    s = input()
    if any([a == b for a, b in zip(s[0:], s[1:])]):
        print(1)
    else:
        print(len(s))