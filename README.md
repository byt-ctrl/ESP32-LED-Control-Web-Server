# 🌐 ESP32-Based LED Control Web Server

- The ESP32 microcontroller executes a basic web server application that enables remote LED control (🔴, 🔵, 🟢, 🟡) using a basic web form. Any web browser enables end-users to control the LED status through a Wi-Fi network connection. Users can observe LED status through the web platform. A powered LED will display its color on the webpage’s matching button. The button's statuschanges to greyed out when an LED is off and allows the user to identify the current operating state easily.

- This project provides users with various essential features to make operation practical and effortless. The web interface enables direct control of four LEDs to turn them on and off. The web page features colored buttons that correspond with the current state of each LED. The red LED status determines whether the red button will display red illumination or display as grey color. A responsive simple design makes the system compatible with desktops and mobile devices. The ESP32 functions as its own Wi-Fi access point thus users need only connect to the ESP32 without depending on any external network.

- Open the project with these essential hardware components at hand. The `ESP32 development board` functions as the main equipment throughout this project. The required hardware includes four `LEDs for red, blue, green and yellow` illumination and several resistors set at `230Ω to 500Ω` and a `breadboard` coupled with `jumper wires`.

- The ESP32 requires the Arduino IDE for uploading code because it serves as its software interface. Performing the installation of the ESP32 board support can easily be achieved through the Library Manager within your IDE. A URL added to Arduino IDE preferences allows users to download the required board package for the installation process of the ESP32. The installed package allows you to make your ESP32 board selection for writing code.

- The next operation after finishing software configuration is transmitting the code to the ESP32. The board is not recognized by your computer which suggests you require `CP210x USB to UART Bridge drivers` for installation. The `CP210x USB to UART Bridge drivers` act as fundamental components that enable smooth data exchange between the computer system and ESP32 board. Users can obtain required `CP210x USB to UART Bridge VCP drivers` for their operating system through the Silicon Labs website at https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers. After driver installation if required the program can be sent to the ESP32 board through the Arduino IDE.

- A successful upload of the code enables you to connect with the ESP32 Wi-Fi access point. You must open the Serial Monitor inside the Arduino IDE to locate the IP address of your ESP32 device which normally displays at `192.168.4.1`. After obtaining the address navigate your computer or smartphone to the ESP 32 Wi-Fi network through the available password 12345678 (this security key can be modified from the code). The ESP32 IP address becomes visible after connection when you use any web browser to access the web interface.

- The web page contains distinctive buttons which activate each of the four LEDs. You can use a browser button to activate or deactivate the LED associated with that button on the web interface. The web page shows real-time status updates of all LEDs so users can monitor and control them through distance with ease.

- Each LED in the setup requires connection to a designated GPIO pin that exists on the ESP32 board. The wiring scheme connects the red LED to GPIO Pin 2 and the blue LED to GPIO Pin 4 alongside the green LED to GPIO Pin 5 and the yellow LED to GPIO Pin 18. The series connection of a 220Ω current-limiting resistor is necessary for each LED to defend against excessive currents which could damage their functionality. Connecting the anode (longer leg) of each LED to its corresponding GPIO pin while directing the cathode (shorter leg) to GND through a 220Ω resistor constitutes the foundation of the connection.

- You can join the project by creating a fork of the repository followed by making changes and then processing them with a pull request. Every participant can join by sharing their ideas and by making enhancements to the project. The project maintains Apache License 2.0 protection thus check the [LICENSE](LICENSE) file for additional details.

- The ESP32 startup project serves as a fantastic starting point for programmers to learn web servers alongside control systems and IoT applications. A wireless LED control system can be established through minimal hardware components combined with brief programming code.
