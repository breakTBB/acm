from os import system
import time

system("g++ -o brute brute.cpp")
system("g++ -o std std.cpp")
i = 1

while True:
    system("python gen.py")
    system("brute <in >bout")
    system("std <in >sout")
    time.sleep(2)
    if(system("fc bout sout")):
        print("GG")
        exit(0)
    print("Passed %d..."%i)
    i += 1
