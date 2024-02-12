# Bertram Labs Coffee Break Simulation

# Description
Welcome to my solution for the coffee bill dilemma! The program starts by assuming the same seven coworkers will always be present each day and always order the same drink. Bob and Jeremy will be the first two to order, with their favorite drinks pre-selected, and will only be asked for the sizes they would like. The remaining five coworkers will give their drink orders, names, and drink sizes. Each employee's drink price will be added to their debt. After everyone has ordered, the person with the largest outstanding balance will pay for that day's bill. If there is a conflict where multiple people have the highest debt, the last person to order will pay the tab. The price of the bill will be subtracted from that person's debt. After each day, the user has the choice to either continue the program for another day or exit the loop.

# RUNNING
To ensure the menu displays as intended, run the program in full screen.

TO COMPILE:

g++ -Wall -Werror -Wpedantic -std=c++17 driver.cpp coffeeBreak.cpp


THEN RUN EITHER (macOS): 

./a.out menu.txt


OR RUN (Windows):

./a.exe menu.txt