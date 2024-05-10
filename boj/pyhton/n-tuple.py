from collections import Counter

def solution(tuple):

    answer = []
    array = []
    nowInt = ''

    for i in range(len(tuple)):
        if tuple[i] != '{' and tuple[i] != '}' and tuple[i] != ',':
            nowInt += tuple[i]

        elif tuple[i] == ',' or tuple[i-1] == tuple[i] and tuple[i] == '}':
            array.append(nowInt)
            nowInt = ''

    temp = Counter(array)
    sorted_temp = sorted(temp.items(), key = lambda item: item[1], reverse = True)
    for i in sorted_temp:
        answer.append(int(i[0]))

    return answer