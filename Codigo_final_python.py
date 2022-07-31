from pyfirmata import Arduino, util
import serial
import os
import time
import webbrowser
from tkinter *

print("Start")
port = "COM3" 
bluetooth = serial.Serial(port, 9600, timeout=0.05)
print("Conectado")
bluetooth.write(b'8')
valor = 0
char = ""

while True: 
    char = str(bluetooth.read())
    
    if char == "b'0'":
        print(char)
        print("Abrindo Chrome")
        os.startfile('chrome.exe')
    if char == "b'1'":
        print(char)
        print("Abrindo Visual Studio Code")
        os.startfile('C:/Users/user.Gustavo Ferrari/AppData/Local/Programs/Microsoft VS Code/Code.exe')
    if char == "b'2'":
        print(char)
        print("Abrindo Git Hub")
        webbrowser.open("https://github.com")
    if char == "b'3'":
        print(char)
        print("Abrindo CMD")
        os.startfile('cmd.exe')
    if char == "b'4'":
        print(char)
        print("Abrindo Outlook")
        os.startfile('C:/ProgramData/Microsoft/Windows/Start Menu/Programs/Outlook 2016.lnk')
    if char == "b'5'":
        print(char)
        print("Abrindo Stackoverflow")
        os.startfile('https://pt.stackoverflow.com/')
    if char == "b'6'":
        print(char)
        print("Abrindo Git Bash")
        webbrowser.open("C:/Program Files/Git/git-bash.exe")
    if char == "b'7'":
        print(char)
        print("Abrindo VirtualBox")
        os.startfile('C:/Program Files/Oracle/VirtualBox/VirtualBox.exe')
  
