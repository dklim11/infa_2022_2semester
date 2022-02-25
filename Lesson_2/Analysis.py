import numpy as np
import matplotlib.pyplot as plt

"""
1)
Let disposition be located in the centre of the cristall.
I suppose that cristall has not even N (in order to make
all directions equal to each other).
For each N there was completed 10 experiments. 

N1 = [5, 9, 13, 17, 21, 25]
Steps1 = [4.5, 18.5, 42, 74, 117, 169]

plt.title('Steps as function of Area')
plt.plot(N1, Steps1)
plt.show()
"""
"""
mu, sigma = 100, 15
x = mu + sigma * np.random.randn(10000)
# histogram for the second experiment
n, bins, patches = plt.hist(x, 50, density=True, facecolor='g', alpha=0.8)

plt.xlabel('Area')
plt.ylabel('Number of steps')
plt.title('Steps(Area)')
plt.axis([50, 160, 0, 0.04])
plt.grid(True)
plt.show()
"""
"""
2)
"""
X = np.linspace(5, 100, 20)
Y = [148, 65, 37, 24, 17, 12, 9, 6, 5, 4, 3, 2, 1, 1, 1, 0, 0, 0, 0, 0]

"""
Bound is equal to 83 percents(after this point 0 steps are necessary)
If average number of steps is double, than bound is around 86.(???)
"""
plt.title('Steps as function of area-percentage')
plt.xlabel(r'percentage')
plt.ylabel(r'Steps till the stop')
plt.plot(X, Y)
plt.show()

