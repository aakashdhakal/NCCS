import queue

adj_list = {
    "a": ["b", "c","d"],
    "b": ["e"],
    "c": ["g","f"],
    "d": ["h","i"],
    "e": [],
    "f": [],
    "g": [],
    "h": [],
    "i": [],
}

visited = []
queue = []
traverseOp = []

def bfs(visited, adj_list, start_node):
    visited.append(start_node)
    queue.append(start_node)

    while queue:
        s = queue.pop(0)
        traverseOp.append(s)

        for neighbour in adj_list[s]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

    print("The traversed output = ",traverseOp)
        


start_node = input("Enter the node from where you want to traverse = ")
bfs(visited,adj_list,start_node)
