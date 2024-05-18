from pylab import *

L = 100
p = 0.30
z = rand(L,L)
m = z<p
#imshow(m, origin='lower')
#show()

#finding connected regions

from scipy.ndimage import label
lw, num = label(m)

#imshow(lw, origin='lower')
#show()

#color based on the size of the cluster
from scipy.ndimage import sum
area = sum(m, lw, index = arange(lw.max() + 1))
areaImg = area[lw]
imshow(areaImg, origin='lower')
#colorbar()
show()
