def get_opt(s):
    l.append(int(s))
    
    for i in range(1, len(s)):
        if s[i - 1: i] == "33":
            get_opt(s[0: i - 1] + s[i + 1:])
            

t = int(input())
for _ in range(t):
    s = input()
    
    l = []
    get_opt(s)
    
    for u in l:
        if u % 33 == 0:
            print("YES")
            break
    else:
        print("NO")