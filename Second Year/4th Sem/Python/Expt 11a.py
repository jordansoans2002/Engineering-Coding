from tkinter import *
stage= Tk()
stage.title("Jordan")
rollNo= Label(text="9165",font=("Times New Roman",20),pady=10)
rollNo.pack(pady=10)
button= Button(text="Click me",bg='red',fg='white',pady=2)
button.pack(pady=10)
entry= Entry()
entry.insert(END,"This is entry box")
entry.pack(pady=10)
textfield=Text(height=7, width=40, padx=5)
textfield.insert(END,"This is a textfield")
textfield.pack()
stage.mainloop()
