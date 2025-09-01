MOD = int(1e9 + 7)

def solve():
    n = int(input())
    ans = n * (n - 1)
    for i in range(1, n + 1):
        ans = (ans * i) % MOD
        
    return ans

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        print(solve())
    
