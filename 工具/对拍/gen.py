from random import randint

with open("in.txt", "w") as f:
    n = randint(10, 20)
    f.write(str(n) + '\n')
    f.write('3\n')
    f.write('4\n')
    base = randint(1, 20)
    for i in range(n):
        step = randint(1, 20)
        base = base + step
        f.write(str(base) + ' ')
