n = int(input())
print(max([len(x) for x in (''.join(list(input().split()) * 2)).split('0')]))