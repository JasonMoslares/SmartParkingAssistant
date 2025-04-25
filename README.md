**🚗 Smart Parking Assistant**

This Smart Parking Assistant aids drivers during parking through audio and visual signals, improving accuracy and safety. It also monitors slot availability in real-time.

📦 Prerequisites

- Install Node.js
- Install XAMPP for backend server setup
- In your XAMPP directory, navigate to htdocs and paste the parking_project folder inside
- Open XAMPP, start Apache and MySQL, then click "Admin" of MySQL
- In MySQL, create a database and name it "parking"
- Create a table named "photosensor", and add 3 columns, namely "id", "status", "parking_name"
- id is INT, status is VARCHAR(50), and parking_name is VARCHAR(50)
- Make sure AUTO INCREMENT is checked on id column
- Make sure to set the default value of status to "Vacant" using SQL  

⚠️ Network Reminder

Ensure that both your ESP32 device and your PC/Laptop are connected to the same local network for proper communication.

⚙️ Functionality

🅿️ Parking

- "OPEN" – Display shows this when the parking slot is vacant.
- "SAFE" – Detected light from an approaching vehicle.
- "NEAR" – Car is nearing the parking curb.
- "STOP" – Very close to the curb; buzzer activates.
- System checks if the vehicle remains stationary in the "STOP" zone for 3 seconds.
- "GOOD" – If stationary, buzzer and LED turn off.
- System resets and display turns off after a short delay.

🚗 Leaving

- When movement is detected, a servo motor raises its arms to signal the driver to move forward and to alert incoming vehicles.
- Once the car is out of range, the servo stops, and the display returns to "OPEN".
