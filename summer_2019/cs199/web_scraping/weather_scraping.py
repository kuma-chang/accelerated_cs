from bs4 import BeautifulSoup
import requests
import os



os.mkdir("wund_html")
stations = ["KBIS","KFAR","KGFK","KDVL","KJMS","KMOT","KISN"]
for station in stations:
    os.mkdir('wund_html/'+station)



r = requests.get("https://weather.com/weather/tenday/l/Taipei+Taiwan+TWXX0021:1:TW")

soup = BeautifulSoup(r.text, "html.parser")


