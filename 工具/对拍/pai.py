from os import system

system("python gen.py")
system("g++ -o brute brute.cpp")
system("g++ -o std std.cpp")
i = 1

while True:
    
    system("brute <in >bout")
    system("std <in >sout")

    if(system("fc bout sout")):
        print("GG")
        exit(0)
    print("Passed %d..."%i)
    i += 1