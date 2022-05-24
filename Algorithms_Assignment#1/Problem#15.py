def findMinIndex(A):
    minIndex = len(A)
    s = set()
    
    for i in reversed(range(len(A))):
        if A[i] in s:
            minIndex = i
        else:
            s.add(A[i])
 
    if minIndex == len(A):
        return "invalid input"
 
    return minIndex
 
 
test_1 = [5, 6, 3, 4, 3, 6, 4]
test_2 = [1, 2, 3, 4, 5, 6]

print(findMinIndex(test_1))
print(findMinIndex(test_2))