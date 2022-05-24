def groupedArray(A):
    n = len(A)
    indexes = []

    for i in range(0, n):
        if A[i] in indexes:
            continue
        else:
            indexes.append(A[i])
            for j in range(i + 1, n):
                if A[j] == A[i]:
                    indexes.append(A[j])
    return indexes


test_1 = [5, 4, 5, 5, 3, 1, 2, 2, 4]
test_2 = [1, 2, 3, 1, 2, 1]
print(groupedArray(test_1))
print(groupedArray(test_2))
