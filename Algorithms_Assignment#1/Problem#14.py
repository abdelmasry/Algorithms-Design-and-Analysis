def pairOfgivenSum(nums, target):
    l = len(nums)
    setOFnums = set()
    found = False
    k = 0
    while k < l:
        if target > nums[k]:
            if nums[k] not in setOFnums:
                setOFnums.add(target - nums[k])
                k += 1
            else:
                print(target - nums[k], nums[k])
                found = True
                k += 1
        else:
            k += 1
    if not found:
        print("Pair not found")
                
            


test_1 = [5, 2, 6, 8, 1, 9]
target_1 = 12
test_2 = [8, 7, 2, 5, 3, 1]
target_2 = 10
pairOfgivenSum(test_1, target_1)
pairOfgivenSum(test_2, target_2)
