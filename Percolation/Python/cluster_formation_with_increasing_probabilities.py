from pylab import *
from scipy.ndimage import label
from scipy.ndimage import sum

L = 100
probabilities = [0.2, 0.3, 0.4, 0.5, 0.6, 0.7]

z = rand(L,L)

for i in range(len(probabilities)):
	p = probabilities[i]
	m = z<p 
	lw, num = label(m)
	area = sum(m, lw, index = arange(lw.max() + 1))
	areaImg = area[lw]
	subplot(2, 3, i+1)
	tit = 'p='+str(p)
	imshow(areaImg, origin = 'lower')
	title(tit)
	axis()
show()
