def solution(rows, columns, queries):
    
    matrix = [[(i*columns+j+1) for j in range(columns)] for i in range(rows)]
    answer = []
    
    for i in queries:
        a,b,c,d = i
        a -= 1
        b -= 1
        c -= 1
        d -= 1

        # list로 만들까? 
        upper_right = matrix[a][d]
        bottom_left = matrix[c][b]
        bottom_right = matrix[c][d]

        rotation_list = []
        
        rotation_list.append(upper_right)
        rotation_list.append(bottom_left)
        rotation_list.append(bottom_right)
        
        for up_side in range(d,b,-1):
            matrix[a][up_side] = matrix[a][up_side-1]
            rotation_list.append(matrix[a][up_side])

        for right_side in range(c,a,-1):
            if right_side-1 != a:
                matrix[right_side][d] = matrix[right_side-1][d]
            else:
                matrix[right_side][d] = upper_right
            rotation_list.append(matrix[right_side][d])

        for bottom_side in range(b,d):
            if bottom_side+1 != d:
                matrix[c][bottom_side] = matrix[c][bottom_side+1]
            else:
                matrix[c][bottom_side] = bottom_right
            rotation_list.append(matrix[c][bottom_side])

        for left_side in range(a,c):
            if left_side != c:
                matrix[left_side][b] = matrix[left_side+1][b]
            rotation_list.append(matrix[left_side][b])

        matrix[c-1][b] = bottom_left

        answer.append(min(rotation_list))
    
    return answer