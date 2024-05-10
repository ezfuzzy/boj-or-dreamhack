def solution(places):
    answer = []

    for array in places: ## 방마다   
        p_position = []

        for i in range(len(array)): # 줄마다 
            new_list = []

            for j in range(len(array)):
                if array[i][j] == 'P':
                    p_position.append([i, j])

            

        if len(p_position) == 0:
            answer.append(1)
            continue

        for i in range(len(p_position)):
            a, b = p_position[i]
            manhaton_distance = False

            for j in range(i+1, len(p_position)):
                x, y = p_position[j]
                if abs(a-x)+abs(b-y) < 2:
                    manhaton_distance = True
                    break
                elif abs(a-x)+abs(b-y) == 2:
                    if a == x:
                        if array[a][b+1] == 'O':
                            manhaton_distance = True
                    elif b == y:
                        if array[a+1][b] == 'O':
                            manhaton_distance = True
                    else:
                        if b < y:
                            if array[a][b+1] == 'O' or array[a+1][b] == 'O':
                                manhaton_distance = True
                        elif b > y:
                            if array[a][b-1] == 'O' or array[a+1][b] == 'O':
                                manhaton_distance = True
                       
            if manhaton_distance:
                answer.append(0)
                break
            if i == len(p_position) - 2:
                answer.append(1)
                break
        
    return answer



places = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
print(solution(places))


