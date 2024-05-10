def solution(s):

    s = s.split(' ')
    

    for i, char in enumerate(s):
        char = list(char)

        for j in range(len(char)):
            if j % 2 == 0:
                char[j] = char[j].upper()
            elif j % 2 == 1:
                char[j] = char[j].lower()
        char = ''.join(char)
        s[i] = char
    s = ' '.join(s)

    return s