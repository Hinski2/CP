s1 = input()
s2 = input()
a, b = len(s1) - 1, len(s2) - 1
while a != -1 and b != -1 and s1[a] == s2[b]:
    a -= 1
    b -= 1
print(a + b + 2)
    