import random
from problems_all import *
from problems_solved import *

problems_to_solve = [p for p in problems_all if p not in problems_solved]

print(random.choice(problems_to_solve))


