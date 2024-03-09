t = int(input())
def num(x):
    if x == '0': return 10
    return ord(x) - ord('0')

for _ in range(t):
    s = input()
    ans = abs(num(s[0]) - 1)
    ans += abs(num(s[1]) - num(s[0]))
    ans += abs(num(s[2]) - num(s[1]))
    ans += abs(num(s[3]) - num(s[2]))
    
    print(ans + 4)
