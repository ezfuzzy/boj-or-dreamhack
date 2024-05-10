def solution(n):
    
    #snail = [[i+j for j in range(i)]for i in range(1, n+1)]
    snail = [[0]* i for i in range(1, n+1)]

    cycle = n
    temp_down = 0
    temp_right = 1
    temp_diagonal = 0

    count = 1
        
    while cycle > 0:
        for i in range(cycle):
            if snail[2*temp_down][temp_down] != count:
                snail[2*temp_down+i][temp_down] = count
                count += 1

        if cycle != 1:
            temp_down += 1
            cycle -= 1
        else:
            break
        

        for j in range(cycle):
            if snail[n-temp_right][temp_right] != count:
                snail[n-temp_right][temp_right+j] = count
                count += 1
        if cycle != 1:
            temp_right += 1
            cycle -= 1
        else:
            break

        for k in range(cycle):
            if snail[n-2-temp_diagonal][n-2-2*temp_diagonal] != count:
                snail[n-2-temp_diagonal-k][n-2-2*temp_diagonal-k] = count
                count += 1
        if cycle != 1:
            temp_diagonal += 1
            cycle -= 1
        else:
            break

    answer = sum(snail, [])
    return answer


print(solution(8))

