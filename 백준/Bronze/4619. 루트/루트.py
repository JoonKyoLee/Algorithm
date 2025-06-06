while (test_case := input()) != '0 0':
    B, N = map(int, test_case.split())

    for i in range(1, B + 1):
        if i ** N <= B <= (i + 1) ** N:
            num1 = B - (i ** N)
            num2 = ((i + 1) ** N) - B

            if num1 > num2:
                print(i + 1)
            else:
                print(i)
            break
