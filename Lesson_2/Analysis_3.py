import numpy as np
import matplotlib.pyplot as plt

N = [5, 9, 13, 17, 21, 25, 30, 35, 40, 50]
Steps = [5, 17, 37, 65, 101, 146, 194, 289, 358, 549]

Percentage = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 96, 97, 98, 99]
Steps_stop = [5591, 1880, 940, 546, 354, 240, 168, 122, 91, 66, 50, 37, 27, 20, 14, 9.5, 6, 3.1, 1.3, 0.98, 0.7, 0.35, 0.1]
figure, axis = plt.subplots(2, 1)

axis[0].plot(N, Steps)
axis[0].set_title(r"Steps to reach the bound(size)")

axis[1].plot(Percentage, Steps_stop)
axis[1].set_title(r"Steps till the stop(Area)")
plt.tight_layout()
plt.show()