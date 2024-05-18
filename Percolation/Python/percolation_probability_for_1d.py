from pylab import *
from scipy.ndimage import label
p = linspace(0.4, 1.0, 100)
nx = len(p)						#nx is the length of array p
Ni = zeros(nx)					#array for storing Ni(ensembl averaged) value for every p values
P = zeros(nx)
N = 1000						#ensemble
L = 100
for i in range(N):				#ensemble
	z = rand(L,L)				#creation of an 2D array of random numbers, used as an lattice. Random Matrix.
	for j in range(nx):
		m = z<p[j]
		lw, num = label(m)
		perc_x = intersect1d(lw[0,:], lw[-1,:])	#to check if the label of any of the clusters of the left side matches with that of any of the clusters of the right side. If matches there is an percolating cluster.
		perc = perc_x[where(perc_x>0)]			#if matches, there is a spanning cluster, size of that cluster[the label of the cluster]. To check if the length of the set of intersections is larger than zero.

		if(len(perc)>0):
			Ni[j] = Ni[j] + 1

Pi = Ni/N      					#ensemble average
plot(p, Pi)
xlabel('$p$')
ylabel('$\Pi$') 				#to write the name of the y_axis as capital greek later Pi 
show()
