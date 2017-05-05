# SmartHome

[demo video here](https://www.youtube.com/watch?v=D-yCt-Ropl0)
Ultimate Smart home Alexa plus iOS solution when you don't want to mess with main voltage 
It uses 2 ESP8266   one for the light switch controlling a sorvo and another one controlling the TV//📺 
Simply Open  .ino  

 Change this to the SS ID of your network and enter the password the ""
 
     const char* ssid = "BYOD";
     const char* password = ""
     
Also  name your device here 

    device_name = "Room Light";



Now Connecting  the servo  to the ESP  connect  the yellow cable  of the servo  to D4  connect  
the black/ brown cable  ground  and  the red cable  to VCC 
and now upload the sketch and you are done✅ 

Remember remember  To open the debugging terminal to note the IP address 
As you will be needing this letter on  for the  iOS app   if you  just want to use Alexa 
this is not necessary  just ask Alexa to discover the   devices
And it will connect automatically

 Make sure  you have copepods installed  and open  the Room lights.xcworkspace  
 file  go to  the file  name URL   in the iOS target  and widget target   change  
 the IP address  remember  do not change  anything  but IP address  so keep everything   after the backward /
 
    let urlON = "http://172.20.104.8/on"
    let urlOFF = "http://172.20.104.8/off"
    let urlConnect = "http://172.20.104.8/index.html"
    let urlTemp = "http://172.20.104.8/temp"
    


Now you’re ready  to compile  the iOS app  onto your device🚀


 
