fh = open("day1.in").read().split("\n\n")
lst =[]
for line in fh:
  a = sum(map(int,line.split("\n")))
  lst.append(a)
lst.sort()
print(lst[-1])
print(lst[-1]+lst[-2]+lst[-3])