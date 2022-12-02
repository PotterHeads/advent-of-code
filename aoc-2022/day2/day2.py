# Opponent: A is rock, B is paper, C is scissors
# Player: X is rock, Y is paper, Z is scissors
all_combination_part_one = {
  'A X': 4,
  'A Y': 8,
  'A Z': 3,
  'B X': 1,
  'B Y': 5,
  'B Z': 9,
  'C X': 7,
  'C Y': 2,
  'C Z': 6,
}

# Opponent: A is rock, B is paper, C is scissors
# Player: X is lose, Y is draw, Z is win

all_combination_part_two = {
  'A X': 3,
  'A Y': 4,
  'A Z': 8,
  'B X': 1,
  'B Y': 5,
  'B Z': 9,
  'C X': 2,
  'C Y': 6,
  'C Z': 7,
}

'''
A Y 4
B X 1
C Z 7
'''

fh = open("day2.in")
first_score = 0
second_score = 0
for i in fh:
  first_score+=(all_combination_part_one[i.strip("\n")])
  second_score+=(all_combination_part_two[i.strip("\n")])
print(first_score)
print(second_score)