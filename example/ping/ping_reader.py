""" PING + ESP TO PY: READER """
# Written by Junicchi - https://github.com/Kebablord
# 15.11.2018

import urllib.request
url = ""  # localhosts's url, ex: https://192.168.102/

def get_data():
	n = urllib.request.urlopen(url).read() # get the raw html data in bytes (sends request and warn our esp8266)
	n = n.decode("utf-8") # convert raw html bytes format to string :3
	data = n.split() # split datas we got. (if you programmed it to send more than one value) It splits them into seperate list elements.
	data = list(map(int, data)) # turn datas to integers, now all list elements are integers.
	global data # this is our final data as list
	# You can even do maths with this final data, i mathematically calculated my ping's datas to cm to measure things :3


while True:
	get_data()
	print("The measured distance is: "+data) # it's all :D
	input("To test it again press enter.")