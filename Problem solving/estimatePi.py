"""
    Problem: Using a set of random numbers, estimate the value of Pi
"""

from random import random


def estimate_pi(n):
    inside = outside = 0  # Counter for points inside the circle and outside circle but inside the square
    while n != 0:  # n is sample size
        x = random()  # current (x, y) co-ordinate
        y = random()

        if x ** 2 + y ** 2 <= 1:  # determine if (x, y) lies inside the circle by pythagoras theorem
            inside = inside + 1  # count the points inside and outside the circle
        outside = outside + 1
        n = n - 1
    pi = 4 * inside / outside  # estimate the value of pi
    return pi


if __name__ == '__main__':
    n = int(input("Enter size of sample : "))
    strPi = '0.0000000'
    print("Estimating value of pi with sample size of ", n)
    while strPi[:6] != '3.1415':
        pi = estimate_pi(n)
        print(pi, end='\t')
        strPi = str(pi)
    print("\n\nPi estimated correctly up to 4 decimal places")
