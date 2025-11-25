import cv2
import numpy as np

img = cv2.imread("cachirula.jpg")

kernel_x = np.array([[1,0,-1],
                     [2,0,-2],
                     [1,0,-1]])
kernel_y = np.array([[1,2,1],
                     [0,0,0],
                     [-1,-2,-1]])

gris = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

gx = cv2.filter2D(gris, -1, kernel_x)
gy = cv2.filter2D(gris, -1, kernel_y)

final = np.abs(gx) + np.abs(gy)

final = cv2.erode(final, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3)))

final = cv2.dilate(final, cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3)))



cv2.imshow("Original", img)
cv2.imshow("Gx", gx)
cv2.imshow("Gy", gy)
cv2.imshow("Bordes", final)


cv2.waitKey()