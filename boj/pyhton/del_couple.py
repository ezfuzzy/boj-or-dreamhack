from collections import deque
def solution(s):

    nowStack = deque()
    nowStack.append(s[0])
    
    for i in range(1, len(s)):
        temp = ''
        if len(nowStack) != 0:
            temp = nowStack.pop()

        if temp != s[i]:
            if temp != '':
                nowStack.append(temp)
            nowStack.append(s[i])
        
    if len(nowStack) == 0:
        return 1
    else:
        return 0


def solution(s):

    nowString = []

    for i in s:
        if len(nowString) == 0:
            nowString.append(i)
        else:    
            if nowString[-1] == i:
                nowString.pop()
            else:
                nowString.append(i)
    if len(nowString) == 0:
        return 1
    return 0