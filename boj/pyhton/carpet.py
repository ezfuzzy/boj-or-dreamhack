def solution(b, y):

    #  가로 >= 세로
    total = b+y
    
    for length in range(1, int(total/2)):
        if total % length == 0:
          width = int(total / length)

        if b == (2*width + 2*length - 4 ):
            break
    
    return [width, length]
    
    
    
print(solution(10,2))
print(solution(8,1))
print(solution(24,24))
