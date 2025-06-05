T = int(input())

sequence_num = 0
score = 0

for _ in range(T):
    test_case = input()
    score = 0
    sequence_num = 0

    for i in range(len(test_case)):
        if test_case[i] == 'O':
            sequence_num += 1
            score += sequence_num
        else:
            sequence_num = 0

    print(score)
