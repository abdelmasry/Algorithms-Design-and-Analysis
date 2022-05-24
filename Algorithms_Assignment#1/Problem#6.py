"""
A more efficient and scalable way is to use multimaps. 
The idea is to map from each column value that we want to join to all the rows that contain it, 
to generate a multimap from a table out of both tables.
The multimap generated has to be hash-based.
"""


from collections import defaultdict

# Function that perform join operation
# on the two tables
def hashJoin(table1, index1, table2, index2):

	h = defaultdict(list)

	# Hash
	for s in table1:
		h[s[index1]].append(s)

	# Perform join operation
	return [(s, r) for r in table2 for s in h[r[index2]]]

# The result of the join will be a new table with the same properties as a multimap using an iterator to search for the elements #