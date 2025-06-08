T = int(input())

for _ in range(T):
    line = input()
    stack = []
    parenthesis = True

    for i in range(len(line)):
        if line[i] == '(':
            stack.append(line[i])
        if line[i] == ')':
            if stack:
                stack.pop()
            else:
                parenthesis = False
                break

    if stack:
        parenthesis = False

    print("YES" if parenthesis else "NO")
