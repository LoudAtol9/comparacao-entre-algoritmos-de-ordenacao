import subprocess

import random

import numpy as np
from scipy.linalg import lstsq
import matplotlib.pyplot as plt


def graph(x_axis, y_axis, p, title):
    plt.plot(x_axis, y_axis, 'o', label='data')

    xx = np.linspace(0, 170000, 101)
    yy = p[0] + p[1]*xx**2

    plt.plot(xx, yy, label="minimos quadrados por $y = a + bx^2$")

    plt.title(title)
    plt.xlabel("Tamanho da lista (n elem)")
    plt.ylabel("Tempo em segundos (s)")

    plt.legend(framealpha=1, shadow=True)

    plt.grid(alpha=0.25)

    plt.savefig(title + ".pdf")

    plt.close()

    #plt.show()


def make_random_num(size, mode=4):
    arr = []
    # Gauss
    if mode == 0 : 
        for i in range(size):
            arr.append(random.gauss())
    # Gamma
    elif mode == 1 :
        for i in range(size):
            arr.append(random.gammavariate())
    # Beta
    elif mode == 2 :
        for i in range(size):
            arr.append(random.betavariate())
    # Expo
    elif mode == 3  :
        for i in range(size):
            arr.append(int(random.expovariate()))
    # Uniform
    elif mode == 4  :
        for i in range(size):
            arr.append(str(int(random.uniform(0, 1000))))
    return arr


def least_squares(x_axis, y_axis):
    M = x_axis[:, np.newaxis]**[0,2]
    p, res, rnk = lstsq(M, y_axis)

    return p


def run_file(my_args):
    teste = subprocess.run(args=my_args, stdout=subprocess.PIPE)
    tempo = teste.stdout.splitlines()

    return int(tempo[0])


if __name__ == '__main__':

    step = 1000
    end = 170000

    path = "build/"
    files = ["bubble", "heap", "insertion", "merge", "quick", "selection"]
    times = [[], [], [], [], [], []]
    posfix = "_sort.exe"

    intervals = []
    random_num = []

    y = []

    for size in range(step, end, step):
        intervals.append(size)
        random_num = make_random_num(size, 4)
        for j in range(0,6):
            random_num.insert(0, path + files[j] + posfix)
            times[j].append(run_file(random_num))
        random_num.clear()
            
    x = np.array(intervals)

    for i in range(0,6):
        y.append(np.array(times[i]))
        M = x[:, np.newaxis]**[0,2]
        p, res, rnk, s = lstsq(M, y[i])
        graph(x, y[i], p, files[i])

#    step = 10000
#    end = 170000
#
#    filename = "build/bubble_sort.exe"
#    random_num = []
#    times = []
#    intervals = []
#
#    for size in range(step, end, step):
#        random_num = make_random_num(size)
#        intervals.append(size)
#        random_num.insert(0, filename)
#        times.append((run_file(random_num)))
#    
#    y = np.array(times)
#    x = np.array(intervals)
#    M = x[:, np.newaxis]**[0,2]
#    p, res, rnk, s = lstsq(M, y)
#
#    plt.plot(x, y, 'o', label='data')
#
#    xx = np.linspace(0, 170000, 101)
#    yy = p[0] + p[1]*xx**2
#
#    plt.plot(xx, yy, label="minimos quadrados por $y = a + bx^2$")
#
#    plt.title("bubble_sort")
#    plt.xlabel("Tamanho da lista (n elem)")
#    plt.ylabel("Tempo em segundos (s)")
#
#    plt.legend(framealpha=1, shadow=True)
#
#    plt.grid(alpha=0.25)
#
#    plt.savefig("bubble_sort" + ".pdf")
#
#    stop = 1
    