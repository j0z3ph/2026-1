import cv2
import numpy as np

imagen = cv2.imread("Shein.png")

h, w, c = imagen.shape

nueva_imagen = np.zeros((h,w,c), np.uint8)

#nueva_imagen = np.clip(imagen.astype('int32') + 50, 0, 255).astype('uint8')

for i in range(h):
    for j in range(w):
        prom = ((imagen[i,j][0].astype('int32') + imagen[i,j][1].astype('int32') + imagen[i,j][2].astype('int32'))//3).astype('uint8')
        nueva_imagen[i,j] = [prom, prom, prom]

cv2.imshow("Shein", imagen)
cv2.imshow("-50 Shein", nueva_imagen)
cv2.waitKey()