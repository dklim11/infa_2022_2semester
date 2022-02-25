import numpy as np
import matplotlib.pyplot as plt

"""
Let disposition be located in the centre of the cristall.
I suppose that cristall has not even N (in order to make
all directions equal to each other).
For each N there was completed 10 experiments. 
"""

N1 = [5, 9, 13, 17, 21, 25, 30, 35, 40, 50]
Steps = [4.5, 18.5, 42, 74, 117, 169, 245, 342, 441, 705]

plt.xlabel('Area')
plt.ylabel('Number of steps')
plt.title('Steps(Area)')
plt.plot(N1, Steps)
plt.grid(True)
plt.show()