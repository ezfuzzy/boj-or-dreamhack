def solution(s):
    
    s = s.lower() # case 1

    temp_id = ""

    for i in s: # case 2
        if i.isalnum() or i == '-' or i == '_' or i =='.':
            temp_id += i
    if temp_id == "": # case 5
        temp_id = "a"
    while temp_id.count("..") != 0: # case 3
        temp_id = temp_id.replace("..",".")
        
    if temp_id[0] == ".": # case 4-1
        temp_id = temp_id[1:]
    if temp_id == "": # case 5
        temp_id = "a"
    if temp_id[len(temp_id)-1] == ".": # case 4-2
        temp_id = temp_id[:len(temp_id)-1]
        
    if temp_id == "": # case 5
        temp_id = "a"
    if len(temp_id) >= 16: # case 6
        temp_id = temp_id[0:15]
        if temp_id[14] == ".":
            temp_id = temp_id[:14]
    while True: # case 7
        if len(temp_id) <= 2:
            temp_id += temp_id[len(temp_id)-1]
        else:
            break
    return temp_id


print(solution("=.="))