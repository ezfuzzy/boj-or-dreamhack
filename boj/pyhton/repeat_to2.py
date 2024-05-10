def solution(s):
    
    repeat_Count, zero_Count = 0, 0

    while True:

        if s == "1":
            break

        zero_Count += s.count('0')
        s = bin(len(s.replace('0', '')))[2:]

        repeat_Count += 1

    return [repeat_Count, zero_Count]



s = "01110"	
print(solution(s))