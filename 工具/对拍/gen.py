import random

cnt = random.randint(1, 1000)

with open(r"C:\Users\PRISM17\Desktop\acm-training\工具\对拍\in", "w") as f:
    cnt =    random.randint(1, 10)
    print(cnt, end='\n', file=f)
    for i in range(cnt):
        left = random.randint(1, 10)
        right = left + random.randint(1, 10)
        print(left, end=' ', file=f)
        print(right, end='\n', file=f)
