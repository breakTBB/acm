from os import system
# import time

system("g++ -o pwn pwn.cpp")
system("g++ -o std std.cpp")
# i = 1
# while True:

#     if(system("fc bout sout")):
#         print("GG")
#         exit(0)
#     print("Passed %d..."%i)
#     # i += 1
while True:
    system("python gen.py")
    system("pwn <in >bout")
    system("std <in >sout")
    if(system("fc bout sout")):
        print("GG")
        exit(0)
