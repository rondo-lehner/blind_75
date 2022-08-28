import random
from problems_all import *
# from problems_solved import *

with open("problems_solved.txt", "a+") as f:
    problems_solved = f.readlines()
    problems_to_solve = [p for p in problems_all if p not in problems_solved]
    problem_to_solve = random.choice(problems_to_solve)
    f.write("\n" + problem_to_solve)

print(problem_to_solve)


