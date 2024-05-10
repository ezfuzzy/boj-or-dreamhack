def solution(answers):
    
    best_score = []

    pattern_1 = [1,2,3,4,5]
    pattern_2 = [2,1,2,3,2,4,2,5]
    pattern_3 = [3,3,1,1,2,2,4,4,5,5]

    score = [0, 0, 0]
    
    for i in range(len(answers)):
        if pattern_1[i%len(pattern_1)] == answers[i%len(answers)]:
            score[0] += 1
        if pattern_2[i%len(pattern_2)] == answers[i%len(answers)]:
            score[1] += 1
        if pattern_3[i%len(pattern_3)] == answers[i%len(answers)]:
            score[2] += 1
    
    for j in range(len(score)):
        best_score.append(j,score[j])

    if best_score[2][0] == best_score[1][0]:
        if best_score[0][0] == best_score[1][0]:
            return [best_score[0][1],best_score[1][1],best_score[2][1]]
        else:
            return [best_score[1][1], best_score[2][1]]
    else:
        return [best_score[2][1]]


print(solution([1,3,2,4,2]))