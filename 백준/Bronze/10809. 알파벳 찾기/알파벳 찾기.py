word = input()
alphabet_index = [-1] * 26

for i in range(len(word)):
    index = ord(word[i]) - 97
    if alphabet_index[index] != -1:
        continue
    else:
        alphabet_index[index] = i

for index in alphabet_index:
    print(index, end=" ")
