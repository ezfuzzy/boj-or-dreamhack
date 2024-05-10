def solution(n):
    answer = []
    hanoi(answer, n, 1, 2, 3)
    return answer

def move(arr, _from, _to):
    arr.append([_from, _to])

def hanoi(arr, number_of_disk, _from, _by, _to):

    if number_of_disk == 1:
        move(arr, _from, _to)
        return
    hanoi(arr, number_of_disk-1, _from, _to, _by)
    move(arr, _from,_to)
    hanoi(arr, number_of_disk-1, _by, _from, _to)

# def hanoi(n):

#     def _hanoi(m, s, b, d):
#         if m == 1:
#             yield [s, d]
#         else:
#             yield from _hanoi(m-1, s, d, b)
#             yield [s, d]
#             yield from _hanoi(m-1, b, s, d)
        
#     ans = list(_hanoi(n, 1, 2, 3))
#     return ans


print(hanoi(3))


    