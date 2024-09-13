a, b, ile = map(int, input().split())
lista = [i ^ a for i in range(1, ile)]
listb = [i ^ b for i in range(1, ile)]
print(*lista)
print(*listb)