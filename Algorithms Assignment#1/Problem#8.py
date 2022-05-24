"""
An appropiate way to do a search in this sitiuation is by doing
a jump search on the serial number of the defected equipment obtained
doing so, it will require a knowledge of the size of equipments produced per day, 
and in constructing the jump search algorithm, the block to be jumped will be root the size.
While searching, if the value of the serial at the next jump is greater than the serial of the defected,
then we will stop the jumping process and go back the previous jump and start linear search until,
the serial of the defected is found.
"""
import math
 
def jumpSearch(factory, defected, size):
     
    step = math.sqrt(size)
    prev = 0
    
    while factory[int(min(step, size)-1)] < defected:
        prev = step
        step += math.sqrt(size)
        if prev >= size:
            return -1
    
    while factory[int(prev)] < defected:
        prev += 1     
        if prev == min(step, size):
            return -1
     
    if factory[int(prev)] == defected:
        return prev
     
    return -1