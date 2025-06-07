T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    zero_count = 0
    
    for i in range(N, M + 1):
        num_str = str(i)
        
        for num in num_str:
            if int(num) == 0:
                zero_count += 1
                
    print(zero_count)
