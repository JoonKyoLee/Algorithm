croatia = {
    "c=": 0,
    "c-": 0,
    "dz=": 0,
    "d-": 0,
    "lj": 0,
    "nj": 0,
    "s=": 0,
    "z=": 0
}

index = 0
alphabet = 0

word = input()

while index < len(word):
    if index + 1 < len(word) and word[index] + word[index + 1] in croatia:
        croatia[word[index] + word[index + 1]] += 1
        index += 2
        alphabet += 1
    elif index + 2 < len(word) and word[index] + word[index + 1] + word[index + 2] in croatia:
        croatia[word[index] + word[index + 1] + word[index + 2]] += 1
        index += 3
        alphabet += 1
    else:
        alphabet += 1
        index += 1

print(alphabet)
