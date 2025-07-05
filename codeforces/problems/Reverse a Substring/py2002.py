n = int(input())
s = input()
idx = 1
for a, b in zip(s[:], s[1:]):
    if a > b:
        print("YES")
        print(idx, idx + 1)
        break
    idx += 1
else:
    print("NO")
