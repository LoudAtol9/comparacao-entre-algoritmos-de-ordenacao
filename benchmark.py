import subprocess

import random

import numpy as np
from scipy.linalg import lstsq
import matplotlib.pyplot as plt


def graph(x_axis, y_axis, p, title, func_type="n^2"):

    plt.plot(x_axis, y_axis, 'o', label='dados')

    xx = np.linspace(0, 10000, 100)

    if func_type == "n^2":
        yy = p[0] + p[1]*xx**2
    else:
        yy = p[0] + p[1]*xx

    plt.plot(xx, yy, label="minimos quadrados por $y = a + bx^2$")

    plt.title(title)
    plt.xlabel("Tamanho da lista")
    plt.ylabel("Tempo em microsegundos")

    plt.legend(framealpha=1, shadow=True)

    plt.grid(alpha=0.25)

    plt.savefig(title + ".pdf")

    plt.close()

    #plt.show()

def comp_graph(begin, end, p):
    for i in range(begin, end):
        xx = np.linspace(0, 10000, 100)
    
        if i < 3 :
            yy = p[i][0] + p[i][1]*xx**2
        else:
            yy = p[i][0] + p[i][1]*xx

        plt.plot(xx, yy, label=files[i])

    plt.title("Comparação Geral de " + str(begin) + " a " + str(end) + ".")
    plt.xlabel("Tamanho da lista")
    plt.ylabel("Tempo em microsegundos")

    plt.legend(framealpha=1, shadow=True)

    plt.grid(alpha=0.25)

    plt.savefig("all-sorts_" + str(begin) + "-" + str(end) + ".pdf")

    plt.close()

def make_random_num(size, mode=4):
    arr = []
    # Gauss
    if mode == 0 : 
        for i in range(size):
            arr.append(random.gauss(1,1))
    # Gamma
    elif mode == 1 :
        for i in range(size):
            arr.append(random.gammavariate(1,1))
    # Beta
    elif mode == 2 :
        for i in range(size):
            arr.append(random.betavariate(1,1))
    # Expo
    elif mode == 3  :
        for i in range(size):
            arr.append(int(random.expovariate(1)))
    # Uniform
    elif mode == 4  :
        for i in range(size):
            arr.append(str(int(random.uniform(0, 1000))))
    return arr


def run_file(my_args):
    teste = subprocess.run(args=my_args, stdout=subprocess.PIPE)
    tempo = teste.stdout.splitlines()

    return int(tempo[0])


if __name__ == '__main__':

    step = 1000
    end = 10000

    path = "build/"
    files = ["bubble", "selection", "insertion", "merge", "quick", "heap"]
    times = [[], [], [], [], [], []]
    posfix = "_sort.exe"

    intervals = []
    random_num = []

    y = []

    for size in range(step, end, step):
        intervals.append(size)
        random_num = make_random_num(size, 4)
        for j in range(0,6):
            mean = 0
            random_num.insert(0, path + files[j] + posfix)
            for i in range(0, 5):
                mean = mean + run_file(random_num)
            mean = int(mean/5)
            times[j].append(mean)
        random_num.clear()
            
    x = np.array(intervals)
    p = []

    for i in range(0,6):
        y.append(np.array(times[i]))
        if i > 2:
            M = np.vstack([np.ones_like(x), x]).T
            p.append(lstsq(M, y[i])[0])
            graph(x, y[i], p[i], files[i], "nlogn")
        else:
            M = x[:, np.newaxis]**[0,2]
            p.append(lstsq(M, y[i])[0])
            graph(x, y[i], p[i], files[i])

    comp_graph(0, 6, p)
    comp_graph(0, 3, p)
    comp_graph(3, 6, p)

    f = open("func-parameters.txt", "w+")

    for i in range(0,6):
        if i < 2:
            f.write(files[i] + ": " + str(p[i][0]) + " + x^2 * " + str(p[i][1]) + "\n")
        else:
            f.write(files[i] + ": " + str(p[i][0]) + " + x * " + str(p[i][1]) + "\n")
    
    f.close()

    min = []
    max = []
    range_l = []
    variance = []
    sd = []

    for i in range(0,6):    
        min.append(np.amin(times[i]))
        max.append(np.amax(times[i]))
        range_l.append(np.ptp(times[i])) 
        variance.append(np.var(times[i]))
        sd.append(np.std(times[i]))

    f = open("statistic-data.txt", "w+")

    for i in range(0,6):
        f.write(files[i] + ": \n    min   : " + str(min[i]) + "\n    max   : " + str(max[i]) + "\n")
        f.write("    range : " + str(range_l[i]) + "\n    var   : " + str(variance[i]) + "\n    sd    : " + str(sd[i]) + "\n\n")
    
    f.close()
        


    