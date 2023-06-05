import paho.mqtt.client as mqtt
import pygame

pygame.mixer.init()

def on_message(client, userdata, msg):
    print("Received message: " + msg.payload.decode())
    print("Topic: " + msg.topic)
    # Play sound file
    pygame.mixer.music.load("home/pi/Documents/brahms.wav")
    pygame.mixer.music.play()

client = mqtt.Client()
client.on_message = on_message
client.connect("localhost", 1883)  
client.subscribe("send_notification") 

client.loop_start()

while True:
    pass
