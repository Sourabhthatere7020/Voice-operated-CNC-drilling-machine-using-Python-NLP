
import serial
import speech_recognition as sr
import pyttsx3
import time

# Arduino serial port
arduino_port = 'COM6'  # Update with your Arduino serial port

# Initialize the Arduino serial connection
arduino = serial.Serial(arduino_port, 9600, timeout=1)
time.sleep(2)  # Wait for Arduino to establish connection

engine = pyttsx3.init('sapi5')
engine.setProperty('volume', 1.0)
engine.setProperty('rate', 150)
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)
listener = sr.Recognizer()
listener.pause_threshold = 3.0
r = sr.Recognizer()


def send_command(command):
    arduino.write((command + '\n').encode())
    arduino.flush()


def Speak(text):
    print('in speak')
    engine.say(text)
    engine.runAndWait()


def TakeCommand():
    with sr.Microphone() as source:
        print("Listening...")
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source)
        print("Recognizing speech...")
        command = ""
        if audio:
            try:
                # Use Google Speech Recognition to convert speech to text
                command = r.recognize_google(audio).lower()
                print("Command:", command)
            except sr.UnknownValueError:
                print("Unable to recognize speech.")
            except sr.RequestError as e:
                print("Error occurred; {0}".format(e))
            return command


def GetValue(text_val):
    values = text_val.split()
    value = None
    for val in values:
        try:
            value = float(val)

        except Exception:
            continue

    if value is None:
        Speak('Invalid or no value present, please say the value again')
        command = GetValue(TakeCommand())
        print(command)
        return command
    else:
        return value


def listen_and_execute():
    command = TakeCommand()

    if "spindle on" in command:
        return
        # send_command("SpindleOn")

    elif "spindle off" in command:
        return
        # send_command("SpindleOff")
    elif "move x" in command:
        movement = GetValue(command)
        if "negative" in command:
            movement = (-movement)
        print("value: " + str(movement))
        send_command("X" + str(movement))
    elif "move y" in command:
        movement = GetValue(command)
        if "negative" in command:
            movement = (-movement)
        print("value: " + str(movement))
        send_command("Y" + str(movement))
    elif "move z" in command:
        movement = GetValue(command)
        if "negative" in command:
            movement = (-movement)
        print("value: " + str(movement))
        send_command("Z" + str(movement))
    elif "reset" in command:
        send_command("R")
    else:
        print("Unknown command.")


def start_up():
    Speak('welcome to the voice assisted CNC ')
    time.sleep(1)
    while True:
        listen_and_execute()


start_up()
