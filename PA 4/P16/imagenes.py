import cv2
import numpy as np

imagen = np.zeros((1,3,3), np.uint8)
imagen[0,0] = [255,0,0]
imagen[0,1] = [0,255,0]
imagen[0,2] = [0,0,255]

cv2.imwrite("imagen.png", imagen)