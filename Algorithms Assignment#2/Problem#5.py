"""
Given an array of size n such that each element contains either a 'P' for policeman or a 'T'
for thief. Find the maximum number of thieves that can be caught by the police.
Keep in mind the following conditions :
1. Each policeman can catch only one thief.
2. A policeman cannot catch a thief who is more than K units away from him.
"""

# Example 1:
# Input:
# N = 5, K = 1
# arr[] = {P, T, T, P, T}
# Output: 2

# Example 2:
# N = 6, K = 2
# arr[] = {T, T, P, P, T, P}
# Output: 3


battlefield1 = ['P', 'T', 'T', 'P', 'T']
battlefield2 = ['T', 'T', 'P', 'P', 'T', 'P']
battlefield3 = ['P', 'T', 'T', 'P', 'T', 'T', 'T', 'P', 'P', 'T', 'P']
def maxThiefCaught(N, K, battlefield):
    caught = 0
    for i in range(0, N):
        if battlefield[i] == 'P':
            if i == N-1: # handling out of border index
                if 'T' in battlefield[i-K+1:i]:
                    caught +=1
            else :
                if 'T' in battlefield[i:i+K+1] or 'T' in battlefield[i-K:i]:
                    caught += 1
                
    print("Sitiuation is neutralized and thieves caught: ", caught)
                    
# Testing...
maxThiefCaught(5, 1, battlefield1)
maxThiefCaught(6, 2, battlefield2)
maxThiefCaught(11, 3, battlefield3)
                    