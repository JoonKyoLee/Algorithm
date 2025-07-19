import sys

S = sys.stdin.readline().strip()

words = []

for i in range(1, len(S) + 1):
    for j in range(len(S) - i + 1):
        words.append(S[j:j+i])

print(len(set(words)))
