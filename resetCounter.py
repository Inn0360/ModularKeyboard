#Author: Howin Tam
#ResetCounter: Simple Reset Counter to keep track of shiny resets

#Start
#checks to read current file, if there, start from num, otherwise, start from 0
import os

num = 0
print(type(num))


if (os.path.isfile("./resetNum.txt") == True) :
    f = open("resetNum.txt","r")
    num = f.read()
    print("Reset is " + str(num))
    f.close()
else: 
    print("File Doesn't Exist: Starting from 0")
print("=====================================================================")


def saveNum(num):
    f = open("resetNum.txt","w")
    f.write(str(num))
    f.close()

while (True):

    input("-> Press Enter to increment")
    print("=====================================================================")
    num = int(num)
    num += 1 
    print("Reset is " + str(num))
    saveNum(num)








