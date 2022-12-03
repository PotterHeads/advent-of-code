fh = open("day3.in").read().split("\n")
# fh = open("sample.in").read().split("\n")
value = 0
item = 0
for line in fh:
  unique_chars = set()
  mid = len(line) // 2
  sample = set(line[:mid])
  for char in line[mid:]:
    if char in sample:
      if char not in unique_chars:
        unique_chars.add(char)
        num = ord(char)
        if num > 90:
          value+= (num-96)
        else:
          value+= (num-38)
print(value)
for i in range(0,len(fh),3):
  group = fh[i:i+3]
  first_set = set(group[0])
  second_set = set(group[1])
  third_set = set(group[2])
  intersection = list(first_set & second_set & third_set)
  num = ord(intersection[0])
  if num > 90:
    item+= (num-96)
  else:
    item+= (num-38)
print(item)



  
      
  
