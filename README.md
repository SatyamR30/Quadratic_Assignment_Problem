# Quadratic_Assignment_Problem




This repository is an implementation of a local search algorithm (Hill Climbing) to solve the Assignment Problem. The Assignment Problem is a combinatorial optimization problem that involves assigning a set of tasks (clients) to a set of resources (facilities) while minimizing the total cost or objective function value. In this implementation, we aim to find the optimal assignment of clients to facilities.

## Problem Definition

- The size of the problem is defined by `N`, which represents the number of facilities/locations.
- The cost matrix (`cost[N][N]`) represents the cost of assigning a client to a facility. It contains the costs associated with each pair of facilities.
- The flow matrix (`flow[N][N]`) represents the flow (assignments) from clients to facilities. It contains the flow values for each pair of facilities.

## How the Code Works

1. Initialize a random permutation of assignments.
2. Calculate the initial objective function value and display it.
3. Perform local search (Hill Climbing) to improve the solution:
   - Iteratively swap assignments and calculate the new objective function value.
   - If the new objective is lower (indicating an improvement), accept the swap and update the objective value.
   - If the new objective is not better, revert the swap.
   - Continue this process until no further improvements can be made.
4. Display the improved objective value and the optimal permutation (assignment).

## Usage

1. Compile the code using a C++ compiler. For example, you can use g++:

   ```bash
   g++ Quadratic_Assignment_Problem.cpp -o Quadratic_Assignment_Problem
   ```

2. Run the executable:

   ```bash
   ./assignment_problem_solver
   ```

3. The program will output the initial and improved objective values, as well as the optimal assignment.

## Sample Output

```
Initial Objective Value: 178
Improved Objective Value: 156
Optimal Permutation: 3 1 0 2
```

## Customization

- You can modify the `cost` and `flow` matrices to represent your specific assignment problem.
- You can adjust the size of the problem by changing the value of `N`.
- For more complex problems, consider fine-tuning the code or exploring other optimization algorithms and heuristics.

