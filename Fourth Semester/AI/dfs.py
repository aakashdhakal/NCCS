adj_list = {
    "a": ["b", "c"],
    "b": ["d", "e","f"],
    "c": ["g"],
    "d": [],
    "e": [],
    "f": [],
    "g": [],
}

open_list ={}
closed_list = []

for node in adj_list.keys():
    open_list[node] = "not-visited"

def dfs(start_node):
    open_list[start_node] = "visited"
    closed_list.append(start_node)

    for v in adj_list[start_node]:
        if open_list[v] != "visited":
            dfs(v)



start_node = input("Enter the node from where you want to traverse = ")
dfs(start_node)
print("The traversed output is ",closed_list)
