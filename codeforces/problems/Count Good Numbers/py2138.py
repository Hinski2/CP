t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    x = r - l + 1
    
    def d(num) -> int:
        return r // num - (l - 1) // num
    
    ans = x
    ans -= d(2) + d(3) + d(5) + d(7)
    ans += d(6) + d(10) + d(14) + d(15) + d(21) + d(35)
    ans -= d(30) + d(42) + d(105) + d(70)
    ans += d(210)
    
    print(ans)
    
