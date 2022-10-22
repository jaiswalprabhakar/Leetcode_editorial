def solution(s):
    left = 0
    right = 0
    count = 0
    for i in s:
        if (i == '<'):
            count = count + right
        if (i == '>'):
            right += 1
    return count*2
    # Your code here


print(solution("<<>><"))
