import cv2
import numpy as np

img = cv2.imread("cachirula.jpg")
h, w, c = img.shape

kernel = np.ones((7,7)) / 49
chk = kernel.shape[0] // 2
cwk = kernel.shape[1] // 2


img2 = np.zeros((h,w,c), np.uint8)

img2 = cv2.filter2D(img, -1, kernel)
"""
for i in range(chk, h-chk):
    for j in range(cwk, w-cwk):
        suma = 0
        for ik in range(kernel.shape[0]):
            for jk in range(kernel.shape[1]):
                suma = suma + (kernel[ik, jk] * img[i - chk + ik, j - cwk + jk])
        img2[i,j] = suma

"""
cv2.imshow("Cachirula", img)
cv2.imshow("Cachirula Tuneada", img2)

cv2.waitKey()