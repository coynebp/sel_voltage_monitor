import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

FILTER_LENGTH = 16

taps = np.zeros(FILTER_LENGTH)
t = np.arange(0 + (np.pi / 32), np.pi - (np.pi / 32) + np.pi/16, np.pi/16)
taps = np.cos(t)
plt.plot(t, taps)
plt.plot.show()
