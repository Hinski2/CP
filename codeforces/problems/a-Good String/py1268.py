def process(s, c):
   if len(s) == 1: return int(s[0] != chr(c))
    
   n = len(s) 
   mid = n // 2
   l = process(s[:mid], c + 1) + mid - s[mid:].count(chr(c))
   r = process(s[mid:], c + 1) + mid - s[:mid].count(chr(c))
   return min(l, r)
   
    
    
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    
    print(process(s, ord('a')))