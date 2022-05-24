"""
Given an array of jobs where every job has a deadline and associated profit if the job is finished
before the deadline. It is also given that every job takes a single unit of time, so the minimum
possible deadline for any job is 1.
How to maximize total profit if only one job can be scheduled at a time. Time Complexity
less than exponential

"""
# Greedy Algorithm:
# 1) Sort all jobs in decreasing order of profit. 
# 2) Iterate on jobs in decreasing order of profit. For each job , do the following : 
#  a)Find a time slot i, such that slot is empty and i < deadline and i is greatest. Put the job in 
#       this slot and mark this slot filled. 
#  b)If no such i exists, then ignore the job. 


def JobScheduling(jobs):
    n = len(jobs)
    possible = set()
    numofJobs = 0
    for i in range(0,n):
        if jobs[i][1] not in possible :
            possible.add(jobs[i][1])
            numofJobs += 1    
  
    # Sort all jobs according to
    # decreasing order of profit
    for i in range(n):
        for j in range(n - 1 - i):
            if jobs[j][2] < jobs[j + 1][2]:
                jobs[j], jobs[j + 1] = jobs[j + 1], jobs[j]
  
    # To keep track of free time slots
    result = [False] * numofJobs
  
    # To store result (Sequence of jobs)
    job = ['-1'] * numofJobs
  
    # Iterate through all given jobs
    for i in range(len(jobs)):
        for j in range(min(numofJobs - 1, jobs[i][1] - 1), -1, -1):
  
            # Free slot found
            if result[j] is False:
                result[j] = True
                job[j] = jobs[i][0]
                break
  
    print("Maximum Profit sequence of jobs is: ",job)
    
# Testing...    
test1 = [['a', 4, 20],
       ['b', 1, 10],
       ['c', 1, 40],
       ['d', 1, 30]]
  
JobScheduling(test1)  

test2 = [['a', 2, 100], 
       ['b', 1, 19],
       ['c', 2, 27],
       ['d', 1, 25],
       ['e', 3, 15]]

JobScheduling(test2)