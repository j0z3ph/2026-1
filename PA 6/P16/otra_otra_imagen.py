import cv2
import numpy as np

img = cv2.imread("cachirula.jpg")

h, w, c = img.shape

img2 = np.zeros((h,w,c), np.uint8)

#img2 = np.clip(img.astype('int32') - 100,0,255).astype('uint8')

for i in range(h):
    for j in range(w):
        prom = ((img[i,j,0].astype('int32') + img[i,j,1].astype('int32') + img[i,j,2].astype('int32')) // 3).astype('uint8')
        img2[i,j] = [prom, prom, prom]

#img2 = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

cv2.imshow("Cachirula", img)
cv2.imshow("Cachirula Tuneada", img2)

cv2.waitKey()