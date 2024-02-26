
n, q = map(int, input().split())
s = " " + input()
l = [ord(i) - ord('a') + 1 for i in s]

pref = [0 for i in range(n + 1)]
for i in range(1, len(s)):
    pref[i] = pref[i - 1] + l[i]

for i in range(q):
    a, b = map(int, input().split())
    print(pref[b] - pref[a - 1])

