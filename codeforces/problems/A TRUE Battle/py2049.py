t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    print("YES" if s[0] == '1' or s[-1] == '1' or s.count('11') else "NO")
