t = int(input())
for _ in range(t):
    chest, key, k = map(int, input().split())

    if key < chest:
        print(chest)
    elif chest + k >= key:
        print(key)
    else:
        print(key + key - chest - k)