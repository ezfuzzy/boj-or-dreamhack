def solution(s):
    
    if s.isdigit() and (len(s) == 4 or len(s) == 6):
        return True
    return False


print(solution("12345"))