s = list(input().strip())
l, r = 0, len(s) - 1
diff = 0
while l < r:
    if s[l] != s[r]:
        diff += 1 
    l += 1 
    r -= 1 

YES = "YES"
NO = "NO"

if diff >= 2: 
    print(NO)
elif diff == 0 and len(s) % 2 == 0:
    print(NO)
else:
    print(YES)