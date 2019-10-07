import random

def incrementV5(x):
    for i in range(1000000):
        prism = random.randint(-10000, 10000)
        if prism == x + 1:
            return prism
    return random.randint(-10000, 10000)

print(incrementV5(10))
# with open(r"C:\Users\prism\Desktop\acm-training\工具\对拍\in", "w") as f:
#     cnt = random.randint(10, 20)
#     f.write(str(cnt) + '\n')
#     for i in range(cnt):
#         f.write(str(random.randint(10, 1000000)) + '\n')

