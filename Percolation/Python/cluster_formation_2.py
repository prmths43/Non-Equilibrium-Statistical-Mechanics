from pylab import *

L = 20
p = 0.5
z = rand(L,L)
m = z<p
imshow(m, origin=’lower’)
show()
