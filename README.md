# Saving Plants - DIY Plant Watering Device

![image](https://user-images.githubusercontent.com/65546290/208014625-78d8edf9-dc59-4b06-aade-41525554f964.png)

Most of us like having green plants in our homes or offices because they can brighten up our living space, reduce fatigue and stress, improve our moods and productivity, and clean indoor air. However, taking care of them is no easy feat. I grew a potted plant but it ended up with yellow and dead leaves due to water shortage. To avoid following the same old disastrous road, I decided to make an auto plant watering device to save my new plants.
The device mainly includes a water storage container, an electric valve to control water flow, a soil humidity sensor to determine whether the valve will open to water plants, and a liquid level sensor installed outside the container to detect if the liquid level falls under the threshold, which means the container is nearly empty. And I only need to refill it when I receive the water shortage prompt.

# HARDWARE LIST
* ESP32-E IoT Microcontroller
* Non-contact Capacitive Liquid Level Sensor
* Gravity: Analog Waterproof Soil Moisture Sensor
* Adjustable DC-DC Boost Converter
* Relay Module
* Solenoid Valve
* 3D Housing
* Acrylic Sheet
* Water Container
* Irrigation Nozzle
* Nylon Cable Ties

# Connection 
![image](https://user-images.githubusercontent.com/65546290/208014973-0c1b1df1-a54d-45c0-b2c4-86b7b2b6c967.png)

* Connect the liquid level sensor to the main controller's D7/D9 with an adapter.
* The soil moisture sensor goes to the controller's A0 and the relay module to the controller's D12


# Upload Program
Change the content in the box to yours.
![image](https://user-images.githubusercontent.com/65546290/208015933-342258ac-d7a6-4f7f-a18e-2321ae220c90.png)


# Function Test

### Add water to the container through the top hole.
![image](https://user-images.githubusercontent.com/65546290/208015558-496578e6-9e0f-4d4d-a614-9819060c8a3e.png)

### When the soil humidity is lower than the threshold, the valve opens to water our plants through drip irrigation(Here for the convenience of demonstration, I switch on/off the gauge to open/close the valve)
![image](https://user-images.githubusercontent.com/65546290/208015571-cd051723-19c0-4dd9-bd59-3612175ca661.png)

### When the liquid level falls under the sensing point, a water shortage prompt will appear on Blynk.
![image](https://user-images.githubusercontent.com/65546290/208015585-9f74a12d-af4d-49e5-a683-cbd6e19cf66d.png)


The plant-watering device has been used for some time and it really helps a lot. Now I can stop worrying that my plants will die from water shortage or drowning. 

# Thank
Well, that's all for this project.Thanks for reading, feel free to leave your comments if you have any other good ideas!
