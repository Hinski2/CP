t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    s = input()
    while(s and s[0] == 'P'):
        s = s[1:]
    ans.append(max([len(i) for i in s.split('A')]))
print(*ans, sep='\n')