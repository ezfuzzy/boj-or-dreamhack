def solution(s):

    cut_length = 1
    shortest_length = len(s)

    for _ in range(len(s)):
        
        temp, temp_base, temp_result = "","",""
        suspend = False
        dup_count = 1

        if cut_length == int(len(s)/2 +1):
            break

        for j in range(0, len(s), cut_length):
            
            temp = ""

            for k in range(cut_length):
                if j+k > len(s)-1:
                    suspend = True
                    break
                temp += s[j+k]
            if temp_base == "":
                temp_base = temp
                continue

            if temp_base == temp:
                dup_count += 1
                if j+cut_length == len(s):
                    if suspend:
                        temp_result += temp
                    temp_result += str(dup_count) + temp_base
            else:
                if dup_count == 1:
                    temp_result += temp_base
                    if j+cut_length >= len(s):
                        temp_result += temp
                else:
                    if suspend:
                        temp_result += temp
                    temp_result += str(dup_count) + temp_base
                dup_count = 1

            temp_base = temp

        if len(temp_result) < shortest_length:
            shortest_length = len(temp_result)
        cut_length += 1
    
    return shortest_length
            
s = "ababcdcdababcdcd"
solution(s)