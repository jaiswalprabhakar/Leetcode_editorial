def solution(l, t):

    for i in range(len(l)):
        sum = 0
        for j in range(i, len(l)):
            sum = sum + l[j]
            if (sum > t):
                break
            elif (sum == t):
                return [i, j]
    return [-1, -1]


    # Your code here
l = [4, 3, 10, 2, 8]
t = 12
print(solution(l, t))
