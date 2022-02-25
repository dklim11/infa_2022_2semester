import numpy as np
import matplotlib.pyplot as plt

Percentage = np.linspace(5, 100, 20)
Steps = [148, 65, 37, 24, 17, 12, 9, 6, 5, 4, 3, 2, 1, 1, 1, 0, 0, 0, 0, 0]

"""
Bound is equal to 83 percents(after this point 0 steps are necessary)
If average number of steps is double, than bound is around 86.(???)
"""
plt.title('Steps as function of area-percentage')
plt.xlabel(r'percentage')
plt.ylabel(r'Steps till the stop')
plt.plot(Percentage, Steps)
plt.show()

