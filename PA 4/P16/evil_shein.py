import cv2
import numpy as np

imagen = cv2.imread("Shein.png")

h, w, c = imagen.shape

nueva_imagen = np.zeros((h,w,c), np.uint8)

#nueva_imagen = np.clip(imagen.astype('int32') + 50, 0, 255).astype('uint8')

for i in range(h):
    for j in range(w):
        nueva_imagen[i,j] = 255 - imagen[i,j]

cv2.imshow("Shein", imagen)
cv2.imshow("Evil Shein", nueva_imagen)
cv2.waitKey()