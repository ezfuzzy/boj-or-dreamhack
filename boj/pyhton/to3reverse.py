def solution(s):

    temp_3base = ""
    temp_Num = s
    temp_Share, temp_Remainder = 0, ""

    while True:
        if temp_Num < 3:
            temp_3base = str(temp_Num) + temp_3base
            break

        temp_Share = int(temp_Num / 3)
        temp_Remainder = str(temp_Num % 3)

        temp_3base = temp_Remainder + temp_3base

        temp_Num = temp_Share
    
    temp_3base = temp_3base[::-1]
    
    temp_Num = 0
    for i in range(len(temp_3base), 0, -1):
        temp_Num += (3**(i-1))*int(temp_3base[len(temp_3base)-i])

    
    return temp_Num

print(solution(45))