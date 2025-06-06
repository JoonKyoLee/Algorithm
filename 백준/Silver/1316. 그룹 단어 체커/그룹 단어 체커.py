N = int(input())

count = 0

for _ in range(N):
    word = input()
    character = [-1] * 26
    group = True
    for i in range(len(word)):
        if character[ord(word[i]) - 97] == -1:
            character[ord(word[i]) - 97] = i
        else:
            if character[ord(word[i]) - 97] == i - 1:
                character[ord(word[i]) - 97] = i
            else:
                group = False
                break
    if group:
        count += 1

print(count)
