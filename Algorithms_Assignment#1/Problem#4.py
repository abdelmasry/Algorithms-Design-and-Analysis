def Real_Set(multiset):
    real_Set = []
    value = 1
    for i in range(0, len(multiset)):
        if multiset[i] > 0:
            for j in range(0, multiset[i]):
                real_Set.append(value)
            value += 1
        else:
            value += 1
            continue
    return real_Set


def continuous(real_set):
    cont = False
    for i in range(1, len(real_set)):
        if real_set[i] == real_set[i - 1] or real_set[i] == real_set[i - 1] + 1:
            cont = True
        else:
            cont = False
    return cont


def OpsNum(real_set):
    num_of_Ops = 0
    if continuous(real_set):
        num_of_Ops += 1
        
    while continuous(real_set):
        # choose two integers 𝑙 and 𝑟 (𝑙 ≤ 𝑟), then remove one occurrence of 𝑙, one occurrence of 𝑙+1, ...,
        # one occurrence of 𝑟 from the multiset. This operation can be applied only if each number from 𝑙
        # to 𝑟 occurs at least once in the multiset
        mark = set()
        for i in reversed(range(len(real_set))):
            if real_set[i] not in mark:
                mark.add(real_set[i])
                real_set.remove(real_set[i])
                
    # choose two integers 𝑖 and 𝑥 (𝑥≥1), then remove 𝑥 occurrences of 𝑖 from the multiset. This
    # operation can be applied only if the multiset contains at least 𝑥 occurrences of 𝑖
    max = real_set[len(real_set)-1]
    i = 1
    while i <= max:
        x = real_set.count(i)
        if x > 0:
            num_of_Ops += 1
        while x > 0:
            real_set.remove(i)
            x -= 1
        i += 1

    return num_of_Ops

test1 = [1, 4, 1, 1]
test2 = [1, 0, 1, 0, 1]
print(OpsNum(Real_Set(test1)))
print(OpsNum(Real_Set(test2)))