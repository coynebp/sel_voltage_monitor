import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

FILTER_LENGTH = 16

taps = np.zeros(FILTER_LENGTH)
t = np.arange(0 + (np.pi / 72), np.pi - (np.pi / 72) + np.pi/36, np.pi/36)
taps = np.cos(t)
plt.plot(t, taps)
plt.plot.show()
