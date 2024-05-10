def solution(s,n):

    for index, char in enumerate(s):
        s = list(s)
        if char == ' ':
            print("aㅋㅋ")
            continue
        
        asc = ord(char) + n

        if char.isupper():
            if asc > 90:
                asc = (asc-64) % 26
                s[index] = chr(asc+64)
            else:
                s[index] = chr(asc)
        else:
            if asc > 122:
                asc = (asc-96) % 26
                s[index] = chr(asc+96)
            else:
                s[index] = chr(asc)
    
    s = ''.join(s)

    return s

s = "A B"
n = 1
print(solution(s,n))
