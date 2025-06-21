n = int(input())
cache = [-1] * (n + 1)

def dp(k):
    if k <= 1:
        cache[k] = k
        return cache[k]
    if cache[k] == -1:
        cache[k] = dp(k - 1) + dp(k - 2)
    return cache[k]

print(dp(n))
