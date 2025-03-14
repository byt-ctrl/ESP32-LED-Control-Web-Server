//ESP32-LED-Control-Web-Server Project


# include <WiFi.h>

// Network Credentials
const char* ssid="ESP 32";   // SSID can be change
const char* password="12345678";   //Password can be change 

// Web Server Port
WiFiServer server(80);

//Led Pins location
const int ledPin2 = 2;   // Red LED
const int ledPin4 = 4;   // Blue LED
const int ledPin5 = 5;   // Green LED           // All led pin locations can be configure as per use case
const int ledPin18 = 18; // Yellow LED

// LED default states
bool led2State = false;
bool led4State = false;
bool led5State = false;
bool led18State = false;

void setup() 
{
  Serial.begin(115200);  //serial monitor baund

  // Initializing LEDs
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  pinMode(ledPin5,OUTPUT);
  pinMode(ledPin18,OUTPUT);

// To Start WIFI access point
  WiFi.softAP(ssid, password);
  Serial.println("IP Address: " + WiFi.softAPIP().toString());

  // To Start Server
  server.begin();
}




// This loop handles incoming client connection , processes GET requests to toggle LEDs, 
//  and sends back an HTML page with buttons to control diffrent LED states (ON/OFF).
void loop() 
{
  WiFiClient client=server.available();  // waiting for client connections
  
  if (client)   // it checks that the client is connected
  {
    String header = "";  // string to store incoming request

    while (client.connected())  // Start the loop and checks the client is connected
    {
      if (client.available())  // checks if there is any data available from client
      {
        char c = client.read();             // it reads character from the client 
        header+=c;                         // appends the character to the header string [It collects the HTTPS request]
        if (c=='\n')                      // if character is newline [It checks the END request is reached or not]
       
       //See if the client request is related to turning on/off any of the LEDs and change their states appropriately
        {
          if (header.indexOf("GET /2/toggle") >= 0) 
          {
            led2State = !led2State;
            digitalWrite(ledPin2,led2State);
          }
          if (header.indexOf("GET /4/toggle") >= 0) 
          {
            led4State = !led4State;
            digitalWrite(ledPin4,led4State);                 
          }
          if (header.indexOf("GET /5/toggle") >= 0) 
          {
            led5State = !led5State;
            digitalWrite(ledPin5,led5State);
          }
          if (header.indexOf("GET /18/toggle") >= 0) 
          {
            led18State = !led18State;
            digitalWrite(ledPin18,led18State);
          }

        // it sends the https response
          client.println("HTTP/1.1 200 OK");   // Sends the HTTP response status that indicates the success message '200 OK'
          client.println("Content-Type : text/html");  // To specify that content has been return is HTML 
          client.println("Connection : close"); // Tells cliet that Connection will close after response 
          client.println(); 
          client.println("<html><body><h1 style='text-align : center;'> LED Control Web Server </h1>");  // HTML Header content to be displayed to client browser

          // Creating Toggle buttons for each led's
          client.println("<div style='text-align : center ; padding-top : 20px;'>");

          // Red LED Button
          if (led2State)  // checks if RED LED is ON
          {
            client.println("<p><a href='/2/toggle'>  <button style = 'font-size: 20px ; padding: 20px 40px ; margin: 10px;background-color: red;color: white;'> Red LED ON </button></a></p>"); // For indentation
          }  
          else   // checks if RED LED is OFF
          {
            client.println("<p><a href='/2/toggle'>  <button style='font-size: 20px ; padding: 20px 40px;margin: 10px ; background-color: grey ; color: white;'> Red LED OFF </button></a></p>"); // For indentation
          }
  


          // BLue LED Button
          if (led4State)  // checks if BLUE LED is ON
          {
            client.println("<p><a href='/4/toggle'>  <button style='font-size: 20px ; padding: 20px 40px ; margin: 10px ; background-color: blue ; color: white;'> Blue LED ON </button></a></p>"); // For indentation
          } 
          else  // checks if BLUE LED is OFF
          {
            client.println("<p><a href='/4/toggle'>  <button style='font-size: 20px ; padding: 20px 40px ; margin: 10px ; background-color: grey ; color: white;'> Blue LED OFF </button></a></p>"); // For indentation
          }



          // Green Led Button
          if (led5State)  // checks if GREEN LED is ON
          {
            client.println("<p><a href='/5/toggle'>  <button style='font-size: 20px ; padding: 20px 40px ; margin: 10px ; background-color: green; color: white;'> Green LED ON </button></a></p>"); // For indentation
          } 
          else  // checks if GRREN is OFF
          {
            client.println("<p><a href='/5/toggle'>  <button style='font-size: 20px ; padding: 20px 40px ; margin: 10px ; background-color: grey; color: white;'> Green LED OFF </button></a></p>"); // For indentation
          }



          // Yellow LED Button
          if (led18State)  // checks if YELLOW LED is ON
          {
            client.println("<p><a href='/18/toggle'>  <button style='font-size: 20px ; padding: 20px 40px ; margin: 10px ; background-color: yellow ; color: black;'> Yellow LED ON </button></a></p>"); // For indentation
          } 
          else  // checks if YELLOW LED is OFF
          {
            client.println("<p><a href='/18/toggle'>  <button style='font-size: 20px ; padding: 20px 40px ; margin: 10px ; background-color: grey ; color: black;'> Yellow LED OFF </button></a></p>"); // For indentation
          }

          client.println("</div>");
          client.println("</body></html>");
          client.stop();  // Closes The Client Connection (exit())
        }
      }
    }
  }
}
