import cv2
import numpy as np

imagen = cv2.imread("Shein.png")

h, w, c = imagen.shape

nueva_imagen = np.zeros((h,w,c), np.uint8)
kernel = np.ones((7,7)) / 49

print(kernel)

cxk = kernel.shape[0]//2
cyk = kernel.shape[1]//2

for i in range(cyk, h-cyk):
    for j in range(cxk, w - cxk):
        suma = 0
        for ik in range(kernel.shape[0]):
            for jk in range(kernel.shape[1]):
                suma = suma + (kernel[ik,jk] * imagen[i - cyk + ik, j - cxk + jk])
        nueva_imagen[i,j] = suma

cv2.imshow("Shein", imagen)
cv2.imshow("Blur Shein", nueva_imagen)
cv2.waitKey()