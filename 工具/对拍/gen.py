with open("in.txt", "w") as f:
    f.write("1\n1000\n10\n")
    for i in range(1, 1001):
        f.write(str(i) + ' ')