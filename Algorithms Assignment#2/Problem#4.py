# Activity Selection Problem:
"""
Given a set of activities and the starting and finishing time of each activity, find the
maximum number of activities that can be performed by a single person assuming that a
person can only work on a single activity at a time.
"""

#Input:
#[1, 4], [3, 5], {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
#Output:
#[1, 4], [5, 7], {8, 11}, {12, 14}

activities = [[1, 4], [3, 5], [0, 6], [5, 7], [3, 8], [5, 9], [6, 10], [8, 11], [8, 12], [2, 13], [12, 14]]

def activity_selection(activities):
    selected_activites = []
    i = 0
    w = 0
    start = 0
    end = 1
    n = len(activities)
    selected_activites.append(activities[i])
    
    for i in range(1, n):
        if activities[i][start] >= selected_activites[w][end]:
            selected_activites.append(activities[i])
            w += 1
    print(selected_activites)        
            
# Testing...            
activity_selection(activities)            

