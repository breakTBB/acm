import random

with open(r"C:\Users\prism\Desktop\acm-training\工具\对拍\in", "w") as f:
    for i in range(30000):
        for j in range(random.randint(2, 4)):
            c = chr(random.randint(65, 67))
            print(c, file = f, end='')