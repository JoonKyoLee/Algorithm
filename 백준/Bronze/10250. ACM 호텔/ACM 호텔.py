T = int(input())

room_number = 0

for _ in range(T):
    H, W, N = map(int, input().split())
    floor = N % H
    room = N // H

    if floor == 0:
        floor = H
    else:
        room += 1

    room_number = floor * 100 + room
    print(room_number)
