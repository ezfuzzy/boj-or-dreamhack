from itertools import combinations
def solution(user_id, banned_id):


    temp_ban_list = []
    
    for i in banned_id:

        for j in user_id:
            count = 0

            if len(i) == len(j):
                for k in range(len(i)):
                    if i[k] != j[k] and i[k] != '*':
                        break
                    count += 1
                    if count == len(i):
                        temp_ban_list.append(j)
    
    temp = list(combinations(set(temp_ban_list), len(banned_id)))
    temp_error = [] 
    count = 0

    for i in temp:
        i = list(i)
        i.sort(key = len)
        banned_id.sort(key = len)
        
        for j in range(len(banned_id)):
            if len(banned_id[j]) != len(i[j]):
                temp_error.append(count)
                break

        count += 1

    # 여기서 필터링을 해야돼요 

    temp_error.reverse()

    for i in temp_error:
        temp.pop(i)
    temp_error.clear()

    

    temp_error.reverse()

    for i in temp_error:
        temp.pop(i)

    print(temp)
    print(len(temp))

    # for i in temp_ban_list:
    #     alone = True
    #     for j in range(temp_error+1, len(temp_ban_list)):
            
    #         if i == temp_ban_list[j]: # 그냥 같을 경우
    #             alone = False
    #             if len(i) != 2: # 2인 경우엔 웨이트가 1이니까
    #                 if len(i) > len(temp_ban_list[j]):
    #                     NoC *= (len(i)-1) * len(temp_ban_list)
    #                 else:
    #                     NoC *= len(i) * (len(temp_ban_list)-1)
    #             temp_ban_list[j] = ['done']
    #             elif: # 일부가 같을 경우

                    


        #     temp_error += 1
        # if alone:
        #     NoC *= len(i)
    





u = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
b = ["fr*d*", "*rodo", "******", "******"]	
solution(u,b)

