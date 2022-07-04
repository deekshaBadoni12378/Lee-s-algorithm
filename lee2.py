from collections import deque
R = 5
C = 3

class chamb:

	def __init__(self,m: int, n: int):
		self.m = m
		self.n = n

class queuex:
	def __init__(self,pt: chamb, dist: int):
		self.pt = pt
		self.dist = dist


def checkValid(row: int, col: int):
	return ((row >= 0) and (row < R) and (col >= 0) and (col < C))


rowNum = [1, 0, -1, 1]
colNum = [0, 1, 0, 1]


def Lee(mat, source: chamb, destination: chamb):
	
	if mat[source.m][source.n]!=1 or mat[destination.m][destination.n]!=1:
		return -1
	
	visited = [[False for i in range(C)] for j in range(R)]
	 
	visited[source.m][source.n] = True
	
	q = deque()
	
	s = queuex(source,0)
	q.append(s)
	 
	while q:

		curr = q.popleft()
		
		pt = curr.pt
		if pt.m == destination.m and pt.n == destination.n:
			return curr.dist
		
		for i in range(4):
			row = pt.m + rowNum[i]
			col = pt.n + colNum[i]
			

			if (checkValid(row,col) and
			mat[row][col] == 1 and
				not visited[row][col]):
				visited[row][col] = True
				Adjcell = queuex(chamb(row,col),curr.dist+1)
				q.append(Adjcell)
	 
	return -1

mat = [
    [ 1, 0, 1, 0, 1, 0 ],
	[ 1, 0, 1, 0, 1, 0 ], 
	[ 1, 1, 0, 0, 1, 1 ], 
	[ 0, 0, 0, 0, 1, 1 ],
    ]

source = chamb(0,0)
destination = chamb(1,2)
	
dist = Lee(mat,source,destination)
	
if dist!=-1:
		print("Length of the Shortest Path is",dist)
else:
		print("Shortest Path doesn't exist")