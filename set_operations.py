class problem1:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def makeset(self, x):
        self.parent[x] = x
        self.rank[x] = 0

    def findset(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.findset(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.findset(x)
        root_y = self.findset(y)

        if root_x == root_y:
            return

        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1


# Create a DisjointSet instance with 10 elements
ds = problem1(10)

# Perform 10 MAKE-SET operations
for i in range(10):
    ds.makeset(i)

# Perform 4 UNION operations
ds.union(1, 2)
ds.union(3, 4)
ds.union(5, 6)
ds.union(7, 8)

# Perform 3 FIND operations
print("Find set of 1:", ds.findset(1))
print("Find set of 2:", ds.findset(2))
print("Find set of 4:", ds.findset(4))

# Print the structure after every operation
for i in range(10):
    print("Parent of {}: {}".format(i, ds.parent[i]))

"""
code explanation: 

we first write a class that creates a disjoint set data structure
we use init to define the structure of the class
it takes 'n' as an input and creates a list 'parent' of size 0 to n-1
and rank which is another array of zeros of length n. this represents
the rank of each element in the disjoint set.

we then define the makeset function which takes an input x
sets parent of x to x and rank of x to 0

we then define the findset function which takes an input x and 
returns the parent of x. if x is not the parent of itself, it
sets the parent of x to the parent of the parent of x. this is
done recursively until the parent of x is x itself. this is the
root of the tree.

we then define the union function which takes two inputs x and y
and finds the root of x and y. if they are the same, it returns
as they are already in the same set. if the rank of x is less than
the rank of y, it sets the parent of x to y. if the rank of y is
less than the rank of x, it sets the parent of y to x. if the
ranks are equal, it sets the parent of y to x and increments the 
rank of x by 1.

we then create a disjoint set of size 10 and perform 10 makeset
operations. we then perform 4 union operations and 3 findset
operations. we then print the structure of the disjoint set after
every operation.

"""