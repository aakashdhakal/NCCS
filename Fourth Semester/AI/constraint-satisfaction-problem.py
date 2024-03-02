from constraint import *

# Define the problem
problem = Problem()

# Define the variables and their domains
variables = ['WA', 'NT', 'SA', 'Q', 'NSW', 'V', 'T']
colors = ['red', 'green', 'blue']
for variable in variables:
    problem.addVariable(variable, colors)

# Define the constraints
def constraint_function(variable1, color1, variable2, color2):
    if variable1 != variable2:
        if color1 == color2:
            return False
    return True

problem.addConstraint(constraint_function, ['WA', 'NT'])
problem.addConstraint(constraint_function, ['WA', 'SA'])
problem.addConstraint(constraint_function, ['NT', 'SA'])
problem.addConstraint(constraint_function, ['NT', 'Q'])
problem.addConstraint(constraint_function, ['SA', 'Q'])
problem.addConstraint(constraint_function, ['SA', 'NSW'])
problem.addConstraint(constraint_function, ['SA', 'V'])
problem.addConstraint(constraint_function, ['NSW', 'Q'])
problem.addConstraint(constraint_function, ['NSW', 'V'])

# Solve the problem
solutions = problem.getSolutions()

# Print the solutions
for solution in solutions:
    print(solution)