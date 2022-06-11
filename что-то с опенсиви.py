import cv2


capture = cv.CaptureFromCAM(0)
frame = cv.QueryFrame(capture)
cv.SaveImage("capture.jpg", frame)


import ls

