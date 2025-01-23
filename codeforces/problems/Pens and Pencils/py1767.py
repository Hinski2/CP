t = int(input())
for _ in range(t):
    lectures, practucal_classes, pen, pencil, k = map(int, input().split())
    x = (lectures + pen - 1) // pen 
    y = (practucal_classes + pencil - 1) // pencil
    if x + y <= k:
        print(x, y)
    else:
        print(-1)
