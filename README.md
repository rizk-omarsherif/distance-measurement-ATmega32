# Ultrasonic Distance Measurement System with ATmega32

#### System designed to measure distance using the HC-SR04 ultrasonic sensor. It utilizes an ATmega32 microcontroller with an 8MHz frequency to interface with the sensor, process distance measurements, and display the results on an LCD.

## Features

- Implementation follows a layered architecture model for modular design and ease of maintenance.
- Measure distance accurately using the HC-SR04 ultrasonic sensor.
- Display distance values on a 4x16 LCD screen.

## Hardware Components

- ATmega32 Microcontroller
-  HC-SR04 Ultrasonic Sensor
-   4x16 LCD
-   Various passive components (resistors, capacitors, etc.)
-   Power supply
-   Breadboard or PCB for circuit assembly

## Software Components

- GPIO Driver for interfacing with the microcontroller's GPIO pins.
- ICU Driver for configuring Input Capture Unit for measuring pulse width.
- LCD Driver for controlling the display of distance values.
- Ultrasonic Driver for managing communication with the HC-SR04 sensor.

## Implementation

- The project is implemented in C programming language, following a layered architecture model for better organization and maintainability.
- It utilizes the hardware components and software drivers to achieve the desired functionality.


## Usage

- Clone the repository and upload the provided code to an ATmega32 microcontroller.
- Follow hardware setup instructions and connect the required components as specified.
- Power up the system with a suitable power supply.
- The system will start measuring distances and displaying them on the LCD.
- Adjust sensor positioning if necessary for accurate measurements.

## Additional Resources

- [LinkedIn Post](https://www.linkedin.com/posts/omar-sherif-rizk_embeddedsystems-avr-project-activity-7081144826913599488-iWqO?utm_source=share&utm_medium=member_desktop) demonstrates the hardware setup and functionality of the Ultrasonic Distance Measurement System through a video.
- "HC-SR04 Ultrasonic MT Student Tutorial" PDF file for detailed interfacing instructions.
-  ATmega32 datasheet for reference on microcontroller specifications and features.

## Contributing

Contributors are welcome to suggest improvements, report issues, and submit pull requests to enhance the functionality and usability of the project.

## License

This project is licensed under the MIT License, allowing for modification, distribution, and commercial use with proper attribution.
