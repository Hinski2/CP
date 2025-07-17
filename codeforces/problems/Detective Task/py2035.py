t = int(input())
def find_last(s: str, char: str):
    pos = -1
    for idx, u in enumerate(s):
        if u == char:
            pos = idx
    return pos 

for _ in range(t):
    s = input()
    
    if s.count('1') == 0 and s.count('0') == 0:
        print(len(s))
    elif s.count('1') == 0:
        print(s.find('0') + 1)
    elif s.count('0') == 0:
        print(s[::-1].find('1') + 1)
    else:
        l_one = find_last(s, '1')
        f_zero = s.find('0', l_one)
        if f_zero == -1: f_zero = len(s) - 1
        print(f_zero - l_one + 1)
        