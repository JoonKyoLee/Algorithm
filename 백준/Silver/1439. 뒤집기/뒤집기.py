word = input()

continuous_0 = list(word.split("0"))
continuous_1 = list(word.split("1"))

print(min(len(continuous_0) - continuous_0.count(''), len(continuous_1) - continuous_1.count('')))
