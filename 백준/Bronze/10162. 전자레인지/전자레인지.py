T = int(input())

buttons = [0] * 3
time = [300, 60, 10]

for i in range(3):
    if T >= time[i]:
        buttons[i] = T // time[i]
        T = T % time[i]

if T != 0:
    print(-1)
else:
    print(f"{buttons[0]} {buttons[1]} {buttons[2]}")
