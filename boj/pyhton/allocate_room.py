def solution(k: int, reservation_list: list) -> list:
    
    room = [0 for _ in range(k)]
    
    count = 0
    allocate_list = []

    while True: 
        if len(allocate_list) == len(reservation_list):
            break
        if room[reservation_list[count]-1] == 0: # True면 빈방
            room[reservation_list[count]-1] = 1
            allocate_list.append(reservation_list[count])
        else:
            temp_count = reservation_list[count]-1

            temp_count_index = room[temp_count]
            room[temp_count] += 1
            
            while True:
                temp_count += temp_count_index
                if room[temp_count] == 0:
                    room[temp_count] = 1
                    allocate_list.append(temp_count+1)
                    break
                temp_count_index = room[temp_count]
                room[temp_count] += 1

        count += 1
        print(room)
    return allocate_list

n,r = 10,[1,3,4,1,3,1]
print(solution(n,r))

