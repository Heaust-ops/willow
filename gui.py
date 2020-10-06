import tkinter as tk
from time import sleep
import subprocess 
import os
import sys

OUTPUT_TEXT = ""

def restart_program():
    python = sys.executable
    os.execl(python, python, * sys.argv)

def throwaway():
	_ = 0

def redirect_instant(inobj,outobj,after,*a,**k):
    global OUTPUT_TEXT
    while True:
        try:
            data = inobj.read(60)
        except EOFError:
            break
        except KeyboardInterrupt:
            sys.stderr.write("\nError:user interrupted\n")
            after(*a,**k)
        if not data:
            break
        OUTPUT_TEXT = data
        outobj = ""
        print(data)
    after(*a,**k)

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.master.title("Willow Dev Gui")
        self.pack()
        self.create_widgets()



    def create_widgets(self):
        global OUTPUT_TEXT
        OUTPUT_TEXT = ""
        self.master.geometry("300x200")
        self.build = tk.Button(self)
        self.run = tk.Button(self)
        
        self.build["text"] = "Build Project"
        self.build["command"] = self.buildProject
        self.run["text"] = "Run Project"
        self.run["command"] = self.runProject
        self.build.grid(row=1, column=1, padx=5, pady=5)
        self.run.grid(row=2, column=1, padx=5, pady=5)
        
        self.quit = tk.Button(self, text="QUIT", fg="red",
                              command=self.master.destroy)
        self.quit.grid(row=3, column=1, padx=5, pady=50)

    def buildProject(self):
        global OUTPUT_TEXT
        OUTPUT_TEXT = "Building..."
        self.build.destroy()
        self.run.destroy()
        self.quit.destroy()
        self.master.geometry("200x200")
        _ = 0
        x = os.popen('if [ -d "./bin" ]; then rm -Rf ./bin; fi && mkdir bin && cd bin && cmake .. && make && cd ..')
        redirect_instant(x, _, self.create_widgets)


    def runProject(self):
        global OUTPUT_TEXT
        OUTPUT_TEXT = "running..."
        self.build.destroy()
        self.run.destroy()
        self.quit.destroy()
        self.master.geometry("200x200")
        _ = 0
        x = os.popen('if [ -d "./bin" ]; then ./bin/program; fi')
        redirect_instant(x, _, self.create_widgets)

root = tk.Tk()
app = Application(master=root)
app.mainloop() 
