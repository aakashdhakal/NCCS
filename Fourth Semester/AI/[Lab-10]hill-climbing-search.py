sussList = {} # This dictionary holds all the nodes with their successors and their corresponding heuristic value
temp_key_list = [] # Holds key node whose successor is to be inputted
initial_node = str(input("Input initial node: ")) # root node
initial_value = eval(input(f"Input {initial_node}'s heuristic value: ")) # holds heuristic value of root node
numberNode = eval(input(f"How many successor nodes in node '{initial_node}': ")) # number of successor of root node
temp_key_list.append(initial_node)

def nodeInput(numberNode): # Function used to input all nodes with their successor and corresponding heuristic value
    new_node = temp_key_list[0]
    temp_key_list.pop(0)
    new_list = []
    for i in range(numberNode):
        key_name = str(input(f"Enter {i+1}'th successor of {new_node}: "))
        key_value = eval(input(f"Enter {key_name}'s heuristic value: "))
        temp = [key_name,key_value]
        new_list.append(temp)
        sussList[new_node] = new_list
        temp_key_list.append(key_name)
    if len(temp_key_list) != 0:
        new_node = temp_key_list[0]
        new_numberNode = eval(input(f"How many successor nodes in node {new_node}?: "))
        nodeInput(new_numberNode)
    else:
        pass

def sortList(new_list): #Function to sort the selected list in ascending order
    new_list.sort(key = lambda x: x[1])
    return new_list

def hillClimbing_search(node,value): #Function to find shortest path using heuristic value
    new_list = list()
    if node in sussList.keys():
        new_list = sussList[node]
        new_list = sortList(new_list)
        if (value > new_list[0][1]):
            value = new_list[0][1]
            node = new_list[0][0]
            hillClimbing_search(node, value)
        if (value < new_list[0][1]):
            print(f"ANSWER:\nFor given Data, the local maxima is at node '{node}' with heuristic value {value}")
    else:
        print(f"ANSWER:\nFor given Data, the local maxima is at node '{node}' with heuristic value {value}")

nodeInput(numberNode)
print("The user input is as follows: \n", sussList)
hillClimbing_search(initial_node, initial_value)

