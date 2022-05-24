def maxSumOfArray(arr):
    trend_sum = 0
    post_sum = 0
    
    for i in arr:
        if post_sum > trend_sum: recent_sum = post_sum  
        else:                    recent_sum = trend_sum
        trend_sum = post_sum + i
        post_sum = recent_sum
        
    if post_sum > trend_sum:    return post_sum
    else:                       return trend_sum 
 
test1 = [3, 7, 4, 6, 5]
test2 = [3, 5, -7, 8, 10] 

print(maxSumOfArray(test1))
print(maxSumOfArray(test2))