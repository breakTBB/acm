from os import system
import time

system("python gen.py")
system("g++ -o brute brute.cpp")
system("g++ -o std std.cpp")
i = 1

while True:
    
    system("brute <in.txt >bout")
    system("std <in.txt >sout")

    if(system("fc bout sout")):
        print("GG")
        exit(0)
    print("Passed %d..."%i)
    i += 1

    time.sleep(1)