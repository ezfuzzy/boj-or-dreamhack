from itertools import permutations

def solution(num: str):
    
    number_of_prime = 0
    temp_arr = [int("".join(count)) for i in range(len(num)) for count in permutations(list(num), i+1)]
    temp_arr = list(set(temp_arr))
    
    for i in temp_arr:
        if i <= 1:
            continue
        if isPrime(i):
            number_of_prime += 1
    
    return number_of_prime

    
def isPrime(n):

    for i in range(2, n):
        if n % i == 0:
            return False
    return True

print(solution("011"))