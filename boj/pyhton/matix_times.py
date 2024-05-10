def solution(arr1,arr2):

    answer = []
    for x, row in enumerate(arr1):
        temp_sum = []
        
        for z in range(len(arr2[0])):
            sum = 0
            
            for y in range(len(arr2)):        
                sum += row[y] * arr2[y][z]
                
            temp_sum.append(sum)    

        answer.append(temp_sum)

    return answer