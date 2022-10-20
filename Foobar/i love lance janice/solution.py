def solution(x):
    output = []
    for i in x:
        if (i >= 'a' and i <= 'z'):
            output.append(chr(122 - ord(i) + 97))
        else:
            output.append(i)
    return ''.join(output)

    # Your code here
print(solution(input()))
