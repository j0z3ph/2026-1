import cv2
import numpy as np

camara = cv2.VideoCapture(0)

while camara.isOpened():
    ret, img = camara.read()
    if ret:
        cv2.imshow("Video", img)
        
    if cv2.waitKey(1) == 27:
        break

camara.release()
cv2.destroyAllWindows()