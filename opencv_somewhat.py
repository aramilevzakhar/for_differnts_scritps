# import tkinter as tk
# # import tkinter.tkMessageBox
# import tkinter.messagebox as tkMessageBox
# top = tk.Tk()
# def helloCallBack():
#    tkMessageBox.showinfo( "Hello Python", "Hello World")
# B = tk.Button(top, text ="Hello", command = helloCallBack)
# top.geometry('300x300')
# B.pack()
# top.mainloop()

import cv2
import matplotlib.pyplot as plt
import numpy as np



flags = [i for i in dir(cv2) if i.startswith('COLOR_')]

print(len(flags))

c = ""


nemo = cv2.imread('C\\Users\\max\\Pictures\\22.png')

plt.imshow(nemo)
plt.show()










