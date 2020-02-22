t = int(input())
for i in range(t):
    h, m = map(int, input().split())
    if m>0:
        totalMinutes = (24 - h - 1)*60
        totalMinutes += (60 - m)
    else:
        totalMinutes = (24-h)*60
    print(totalMinutes)

