def solution(s):

    count = 0
    for i in s:
        print(i)
        s.pop(count)
        count += 1




u = ["frodo", "fradi", "crodo", "abc123", "frodoc"]	
solution(u)