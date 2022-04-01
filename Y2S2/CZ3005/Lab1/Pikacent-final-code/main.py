import json
import matplotlib.pyplot as plt
from queue import Queue, PriorityQueue
import time
import math

from matplotlib import animation

# Opening JSON file and store JSON object as a dictionary

# Graph dictionary
f = open('g.json')
G = json.load(f)

# Node coordination dictionary
f = open('coord.json')
Coord = json.load(f)

# Edge distance dictionary
f = open('dist.json')
Dist = json.load(f)

# Edge cost dictionary
f = open('cost.json')
Cost = json.load(f)

f.close()


def DFS(G, s, e):
    # Visited set to avoid looping
    visited = set()
    visited.add(s)

    # Normal array is used as a stack to implement LIFO structure
    stack = [s]

    # Dictionary is used to record parent of each nodes
    # Starting node has none parent
    parent = {s: None}

    # Count to record number of nodes visited
    count = 0

    while len(stack):
        count += 1
        node = stack.pop()
        if node == e:
            break

        for neighbour in G[node]:
            if neighbour not in visited:
                stack.append(neighbour)
                parent[neighbour] = node
                visited.add(neighbour)

    print("Number of visited nodes: ", count)

    # Calculate distance and energy
    distance = 0
    energy = 0
    noNodes = 0

    # Construct Path
    path = [e]
    while parent[e]:
        noNodes += 1
        distance += Dist[e + ',' + parent[e]]
        energy += Cost[e + ',' + parent[e]]
        path.append(parent[e])
        e = parent[e]

    path.reverse()
    return path, distance, energy, noNodes


def BFS(G, s, e):
    # Visited set to avoid looping
    visited = set()
    visited.add(s)

    # Queue is used as a stack to implement FIFO structure
    queue = Queue()
    queue.put(s)

    # Dictionary is used to record parent of each nodes
    # Starting node has none parent
    parent = {s: None}

    # Count to record number of nodes visited
    count = 0

    while not queue.empty():
        count += 1
        node = queue.get()
        if node == e:
            break

        for neighbour in G[node]:
            if neighbour not in visited:
                queue.put(neighbour)
                parent[neighbour] = node
                visited.add(neighbour)

    print("Number of visited nodes: ", count)

    # Calculate distance and energy
    distance = 0
    energy = 0
    noNodes = 0

    # Construct Path
    path = [e]
    while parent[e]:
        noNodes += 1
        distance += Dist[e + ',' + parent[e]]
        energy += Cost[e + ',' + parent[e]]
        path.append(parent[e])
        e = parent[e]

    path.reverse()
    return path, distance, energy, noNodes

def UCSDistance(G, s, e):
    # Visited set to avoid looping
    visited = set()
    visited.add(s)
    # Priority queue is used to keep track of the minimal path cost from starting node to current node
    pq = PriorityQueue()
    pq.put((0, s))

    # Depth dictionary to keep track of cost from start to particular node
    Depth = {s: 0}

    # Dictionary is used to record parent of each nodes
    # Starting node has none parent
    parent = {s: None}

    # Count to record number of nodes visited
    count = 0

    while not pq.empty():
        count += 1
        (cost, node) = pq.get()
        if node == e:
            break
        for neighbour in G[node]:
            if neighbour not in visited:
                Depth[neighbour] = cost + Dist[node + ',' + neighbour]
                parent[neighbour] = node
                pq.put((Depth[neighbour], neighbour))
                visited.add(neighbour)
            else:
                oldDepth = Depth[neighbour]
                newDepth = cost + Dist[node + ',' + neighbour]
                if (newDepth < oldDepth):
                    Depth[neighbour] = newDepth
                    parent[neighbour] = node
                    pq.put((Depth[neighbour], neighbour))
    print("Number of visited nodes: ", count)

    # Calculate distance and energy
    distance = 0
    energy = 0
    noNodes = 0

    # Construct Path
    path = [e]
    while parent[e]:
        noNodes += 1
        distance += Dist[e + ',' + parent[e]]
        energy += Cost[e + ',' + parent[e]]
        path.append(parent[e])
        e = parent[e]

    path.reverse()
    return path, distance, energy, noNodes

def UCSCost(G, s, e):
    # Visited set to avoid looping
    visited = set()
    visited.add(s)
    # Priority queue is used to keep track of the minimal path cost from starting node to current node
    pq = PriorityQueue()
    pq.put((0, s))

    # Depth dictionary to keep track of cost from start to particular node
    Depth = {s: 0}

    # Dictionary is used to record parent of each nodes
    # Starting node has none parent
    parent = {s: None}

    # Count to record number of nodes visited
    count = 0

    while not pq.empty():
        count += 1
        (cost, node) = pq.get()
        if node == e:
            break
        for neighbour in G[node]:
            if neighbour not in visited:
                Depth[neighbour] = cost + Cost[node + ',' + neighbour]
                parent[neighbour] = node
                pq.put((Depth[neighbour], neighbour))
                visited.add(neighbour)
            else:
                oldDepth = Depth[neighbour]
                newDepth = cost + Cost[node + ',' + neighbour]
                if (newDepth < oldDepth):
                    Depth[neighbour] = newDepth
                    parent[neighbour] = node
                    pq.put((Depth[neighbour], neighbour))
    print("Number of visited nodes: ", count)

    # Calculate distance and energy
    distance = 0
    energy = 0
    noNodes = 0

    # Construct Path
    path = [e]
    while parent[e]:
        noNodes += 1
        distance += Dist[e + ',' + parent[e]]
        energy += Cost[e + ',' + parent[e]]
        path.append(parent[e])
        e = parent[e]

    path.reverse()
    return path, distance, energy, noNodes


def AStar(G, s, e):
    # Visited set to avoid looping
    visited = set()
    visited.add(s)

    # Priority queue is used to keep track of the minimal path cost from starting node to goal node
    pq = PriorityQueue()
    pq.put((0, s))

    # Depth dictionary to keep track of cost from start to particular node
    Depth = {s: 0}

    # Cost dictionary estimated using geographical distance between start node to particular node
    H = {s: 0}
    x, y = Coord['1']

    # Total estimated cost
    totalCost = {s: 0}

    # Dictionary is used to record parent of each nodes
    # Starting node has none parent
    parent = {s: None}

    # Count to record number of nodes visited
    count = 0
    while not pq.empty():
        count += 1
        (cost, node) = pq.get()
        if node == e:
            break
        for neighbour in G[node]:
            if neighbour not in visited:
                H[neighbour] = math.sqrt((x - Coord[neighbour][0]) ** 2 + (y - Coord[neighbour][1]) ** 2)
                Depth[neighbour] = Depth[node] + Cost[node + ',' + neighbour]
                totalCost[neighbour] = Depth[neighbour] + H[neighbour]
                parent[neighbour] = node
                pq.put((totalCost[neighbour], neighbour))
                visited.add(neighbour)
            else:
                oldDepth = Depth[neighbour]
                newDepth = Depth[node] + Cost[node + ',' + neighbour]
                if (newDepth < oldDepth):
                    Depth[neighbour] = newDepth

                oldCost = totalCost[neighbour]
                newCost = newDepth + H[neighbour]
                if (newCost < oldCost):
                    totalCost[neighbour] = newCost
                    parent[neighbour] = node
                    pq.put((totalCost[neighbour], neighbour))

    print("Number of visited nodes: ", count)

    # Calculate distance and energy
    distance = 0
    energy = 0
    noNodes = 0

    # Construct Path
    path = [e]
    while parent[e]:
        noNodes += 1
        distance += Dist[e + ',' + parent[e]]
        energy += Cost[e + ',' + parent[e]]
        path.append(parent[e])
        e = parent[e]

    path.reverse()
    return path, distance, energy, noNodes


print()
# Task 1
print("Task 1")
print()
start = '1'
end = '50'

# Solving with DFS
print("DFS")
stime = time.time()
p, distance, energy, noNodes = DFS(G, start, end)
etime = time.time()
print("Execution Time: ", etime - stime)
print("Number of nodes in solution path: ", noNodes)
x = []
y = []
print("Shortest path: ", end="")
for i in p:
    if i == end:
        print(i)
    else:
        print(i, "->", end="")
    x.append(Coord[i][0])
    y.append(Coord[i][1])

print("Shortest distance: ", distance)
print("Total energy cost: ", energy)

# Plotting for visualization
# plt.plot(x, y)

print()
# Solving with BFS
print("BFS")
stime = time.time()
p, distance, energy, noNodes = BFS(G, start, end)
etime = time.time()
print("Execution Time: ", etime - stime)
print("Number of nodes in solution path: ", noNodes)
x = []
y = []

print("Shortest path: ", end="")
for i in p:
    if i == end:
        print(i)
    else:
        print(i, "->", end="")
    x.append(Coord[i][0])
    y.append(Coord[i][1])

print("Shortest distance: ", distance)
print("Total energy cost: ", energy)

# Plotting for visualization
# plt.plot(x, y)

print()
# Solving with UCS
print("UCS Distance")
stime = time.time()
p, distance, energy, noNodes = UCSDistance(G, start, end)
etime = time.time()
print("Execution Time: ", etime - stime)
print("Number of nodes in solution path: ", noNodes)
x = []
y = []

print("Shortest path: ", end="")
for i in p:
    if i == end:
        print(i)
    else:
        print(i, "->", end="")
    x.append(Coord[i][0])
    y.append(Coord[i][1])

print("Shortest distance: ", distance)
print("Total energy cost: ", energy)

# Plotting for visualization
# plt.plot(x, y)

print()
# Task 2
print("Task 2")
print()

# Solving with UCS
print("UCS Cost")
stime = time.time()
p, distance, energy, noNodes = UCSCost(G, start, end)
etime = time.time()
print("Execution Time: ", etime - stime)
print("Number of nodes in solution path: ", noNodes)
x = []
y = []

print("Shortest path: ", end="")
for i in p:
    if i == end:
        print(i)
    else:
        print(i, "->", end="")
    x.append(Coord[i][0])
    y.append(Coord[i][1])

print("Shortest distance: ", distance)
print("Total energy cost: ", energy)

# Plotting for visualization
# plt.plot(x, y)


print()
# Task 3
print("Task 3")
print()

# Solving with UCS
print("A Star")
stime = time.time()
p, distance, energy, noNodes = AStar(G, start, end)
etime = time.time()
print("Execution Time: ", etime - stime)
print("Number of nodes in solution path: ", noNodes)
x = []
y = []

print("Shortest path: ", end="")
for i in p:
    if i == end:
        print(i)
    else:
        print(i, "->", end="")
    x.append(Coord[i][0])
    y.append(Coord[i][1])

print("Shortest distance: ", distance)
print("Total energy cost: ", energy)

# Plotting for visualization
# plt.plot(x, y)
#
# plt.text(Coord['1'][0], Coord['1'][1], '{}'.format("Start"))
# plt.text(Coord['50'][0], Coord['50'][1], '{}'.format("End"))
#
# plt.show()
