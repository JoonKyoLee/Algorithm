mushroom = [int(input()) for _ in range(10)]

mushroom_sum = 0
goal = 100

for i in range(len(mushroom) - 1):
    mushroom_sum += mushroom[i]
    if mushroom_sum <= goal <= mushroom_sum + mushroom[i + 1]:
        diff1 = goal - mushroom_sum
        diff2 = mushroom[i + 1] + mushroom_sum - goal
        if diff1 < diff2:
            print(mushroom_sum)
        else:
            print(mushroom_sum + mushroom[i + 1])
        break

    if i == len(mushroom) - 2:
        print(mushroom_sum + mushroom[i + 1])
