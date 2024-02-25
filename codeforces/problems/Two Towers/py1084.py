t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    s1 = input()
    s2 = input()

    s = s1 + s2[::-1]
    itr = 1
    while itr < len(s) and s[itr] != s[itr - 1]:
        itr += 1

    itr += 1
    while itr < len(s) and s[itr] != s[itr - 1]:
        itr += 1
    
    print("YES" if itr >= len(s) else "NO")