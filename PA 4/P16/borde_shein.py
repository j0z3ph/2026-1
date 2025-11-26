import cv2
import numpy as np

imagen = cv2.imread("Shein.png")

gris = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)

kernel_x = np.array([[1,0,-1],
                     [2,0,-2],
                     [1,0,-1]])

kernel_y = np.array([[1,2,1],
                     [0,0,0],
                     [-1,-2,-1]])

gx = cv2.filter2D(gris, -1, kernel_x)
gy = cv2.filter2D(gris, -1, kernel_y)

borde = np.abs(gx) + np.abs(gy)


cv2.imshow("Shein", imagen)
cv2.imshow("Gx", gx)
cv2.imshow("Gy", gy)
cv2.imshow("Borde", borde)

cv2.waitKey()