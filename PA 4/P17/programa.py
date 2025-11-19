import cv2

camara = cv2.VideoCapture(0)

while camara.isOpened():
    ret, img = camara.read()
    if ret:
        cv2.imshow("Camara", img)
        
    if cv2.waitKey(1) == 27: break

camara.release()
cv2.destroyAllWindows()