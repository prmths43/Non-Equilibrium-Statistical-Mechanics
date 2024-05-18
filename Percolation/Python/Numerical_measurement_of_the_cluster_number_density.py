from pylab import *
from scipy.ndimage import label
from scipy.ndimage import sum

L = 20
p = 0.90
z = rand(L)
m = z<p
lw, num = label(m)

labelList = arange(lw.max() + 1)
area = sum(m, lw, labelList)

print(*labelList, sep = ',')
print(*area, sep = ',')
