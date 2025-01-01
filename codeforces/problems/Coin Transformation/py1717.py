t = int(input())
for _ in range(t):
    n = int(input())
    coin_no = 1
    while n > 3: 
        coin_no *= 2
        n //= 4
    print(coin_no)