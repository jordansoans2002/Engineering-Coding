from tkinter import *

def sayHi():
    display.insert(END,chars=enterName.get()[12:])

stage= Tk()
stage.title('Greetings...')
label= Label(text="Enter your name",font=15)
label.pack(pady=7)
enterName= Entry(width=20,font=15)
enterName.pack()
enterName.insert(END,'My name is: ')
submitButton= Button(text='Click Me',font=15,command=sayHi)
submitButton.pack(pady=10)
display= Text(height=7,width=30,font=15)
display.insert(END, chars='Hey ')
display.pack()
stage.mainloop()