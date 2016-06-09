#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>

const char *ssid = "SSID";
const char *password = "Password";

ESP8266WebServer server ( 80 );


void handleRoot() {

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    int val = server.arg ( i ).toInt();
    analogWrite(D0, val);
    //EEPROM.write(0, val);
    //EEPROM.commit();
  }

	String temp = "<html>\
  <head>\
    <title>Deckenlampe</title>\
    <style>\
      body { background-color: #cccccc; }\
    </style>\
    <script src='https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js'></script>\
    <script>\
      function showVal(val){\
        console.log(val);\
        $.get('/',{'val':val});\
      }\
    </script>\
  </head>\
  <body>\
  <h1>Fluepkes Cyberblaster</h1>\
  <form action=\"#\" method=\"POST\">\
    <input type='range' oninput='showVal(this.value)' id='fader'  min='0' max='1024' />\
  </form>\
  </body>\
</html>";
	server.send ( 200, "text/html", temp );
}

void handleNotFound() {
	String message = "File Not Found\n\n";
	server.send ( 404, "text/plain", message );

}

void setup ( void ) {
  EEPROM.begin(512);
  analogWriteFreq(50000);
  analogWrite(D0, 50);
  
	Serial.begin ( 115200 );
	WiFi.begin ( ssid, password );
	Serial.println ( "" );

	// Wait for connection
	while ( WiFi.status() != WL_CONNECTED ) {
		delay ( 500 );
		Serial.print ( "." );
	}

	Serial.println ( "" );
	Serial.print ( "Connected to " );
	Serial.println ( ssid );
	Serial.print ( "IP address: " );
	Serial.println ( WiFi.localIP() );

	if ( MDNS.begin ( "esp8266" ) ) {
		Serial.println ( "MDNS responder started" );
	}

	server.on ( "/", handleRoot );
	server.onNotFound ( handleNotFound );
	server.begin();
	Serial.println ( "HTTP server started" );
}

void loop ( void ) {
	server.handleClient();
}
