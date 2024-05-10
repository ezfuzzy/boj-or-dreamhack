
def solution(line):
    
    m_point = []
    for i in range(len(line)):
        for j in range(len(line)):
            a, b, e = line[i]
            c, d, f = line[j]
            
            if a*d - b*c != 0:
                x = (b*f - e*d) / (a*d - b*c)
                y = (e*c - a*f) / (a*d - b*c)
            
                if x.is_integer() and y.is_integer():
                    x, y = int(x), int(y)
                    
                    if (x,y) not in m_point:
                        m_point.append((x,y))
                
    # find max_x, min_x, max_y, min_y
    x_min, x_max = min(m_point)[0], max(m_point)[0]

    y_min = min(m_point,key = lambda x: x[1])[1]
    y_max = max(m_point,key = lambda x: x[1])[1]
    temp = min(m_point,key = lambda x: x[1])

    answer = [['.']*(abs(x_max-x_min)+1) for _ in range((abs(y_max-y_min)+1))]

    for i in m_point:
        a,b = i
        x,y = abs(y_max-b), abs(x_min-a)
        answer[x][y] = '*'
    
    for i,v in enumerate(answer):
        answer[i] = ''.join(v)
        
    return answer


line1 = [[2, -1, 4], [-2, -1, 4], [0, -1, 1], [5, -8, -12], [5, 8, 12]]
solution(line1)



#solution = lambda line: (lambda rx, ry, s: ["".join("*" if (x, y) in s else "." for x in rx) for y in ry])(*((lambda i, j, s: (range(min(i), max(i) + 1), range(max(j), min(j) - 1, -1), s))(*(lambda s: ([v for v, _ in s], [v for _, v in s], s))(set((x // z, y // z) for x, y, z in [(b * f - e * d, e * c - a * f, a * d - b * c) for (a, b, e) in line for (c, d, f) in line] if z and not (x % z or y % z))))))
