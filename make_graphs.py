import os
import sys
import subprocess

import numpy as np
from scipy.linalg import lstsq
import matplotlib.pyplot as plt


def graph(x_axis, y_axis, title, sort_name):
    plt.plot(x_axis, y_axis, 'o', label='data')

    xx = np.linspace(0, 9, 101)
    yy = x_axis[0] + x_axis[1]*xx**2

    plt.plot(xx, yy, label=sort_name)

    plt.title(title)
    plt.xlabel("Tamanho da lista (n elem)")
    plt.ylabel("Tempo em segundos (s)")

    plt.legend(framealpha=1, shadow=True)

    plt.grid(alpha=0.25)

    plt.savefig(title + ".pdf")

    #plt.show()



def least_squares(x_axis, y_axis):
    M = x_axis[:, np.newaxis]**[0,2]
    p, res, rnk = lstsq(M, y_axis)

    return p


def run_file(program, mode, length, sample):
    output = []

    teste = subprocess.run([program, mode, str(length), str(sample)], stdout=subprocess.PIPE)
    tempo = teste.stdout.splitlines()

    output.append(tempo)

    return output


def main(arg):

    if (int(arg[2]) > 0 and int(arg[3]) > 0):

        lists = []
        intervals = []

        for x in range(int(arg[1])):
            lists.append(run_file("benchmark.exe", arg[1], x * 10, int(arg[2])))
            intervals.append(x)

        insertion = []
        bubble = []
        selection = []
        merge = []
        quick = []

        for x in lists:
            selection.append(x[0])
            bubble.append(x[1])
            insertion.append(x[2])
            merge.append(x[3])
            quick.append(x[4])

        graph(least_squares(selection, intervals), intervals, "Selection-Sort", "Selection")
        graph(least_squares(bubble, intervals), intervals, "Bubble-Sort", "Bubble")
        graph(least_squares(insertion, intervals), intervals, "Insertion-Sort", "Insertion")
        graph(least_squares(merge, intervals), intervals, "Merge-Sort", "Merge")
        graph(least_squares(quick, intervals), intervals, "Quick-Sort", "Quick")

    else:
        print("USAGE: mode(array_or_list) sample_size n_loops")
    