# Fleet-Database-Management-System
This C-based Fleet Management System is designed to help Evergreen Airways track and manage its aircraft fleet in real-time. The program stores information for up to 50 aircraft and provides core functionalities to add, update, delete, search, and report on aircraft data. It uses a binary file (aircraft_data.dat) for persistent data storage between sessions.
Each aircraft entry includes:

•	Identification: ID, Model, and Registration Number.

•	Location: Latitude and Longitude

•	Status Info: Fuel Level, Speed, Maintenance Due (in days)

•	Flight Info: Departing City, Destination, and Estimated Travel Time

All the Key Features:

   	Add Aircraft:
     •	Enter details like ID, model, location (latitude/longitude), fuel level, speed,maintenance days left, departure and destination cities, and estimated travel time.

 •	 The system validates inputs with real-world operational constraints:

   	Fuel level must be between 20% and 100%

   	Speed must not exceed 800 km/h

   	Maintenance due must be at least 2 days

	Update Aircraft: 

•	Modify data such as location, fuel level, speed, maintenance status and flight routes details.

•	 Allows editing of specific fields: location, fuel, speed, maintenance due and 
            destination info
            
•	Ensures updated values also follow constraints.

	Search Aircraft: Find an aircraft quickly using its unique ID.

•	Quickly find and display detailed info about any aircraft in the fleet using its ID.

	Delete Aircraft: Remove an aircraft from the fleet by ID.

•	Permanently remove an aircraft record based on ID.

	Display Fleet: View a full table of all aircraft and their current data.

•	Shows all aircraft records in full detail for easy review and oversight.

	Data Persistence: All data is saved to and loaded from a binary file (aircraft_data.dat) so that records are preserved between program runs. All saved data is automatically loaded on startup

	Compliance Report: Generate a detailed report highlighting aircraft with :Low fuel (<20%),High speed (>800 km/h) and Imminent maintenance (≤2 days).

	Main Features: 

•	Aircraft Data Management using “struct Aircraft” to store all aircraft details like model, location,fuel,route etc.

•	Array fleet[50]: Stores up to 50 aircraft.

•	File Handling: Uses fread/fwrite to load/save data in aircraft_data.dat.

•	Core Functionalities:

	Add() – Register a new aircraft with validation.

	Update() – Modify fuel, speed, location, maintenance, and route.

	Search() – Lookup aircraft by ID.

	Delete()– Remove aircraft from the fleet.

	Display()– Show all aircraft in a formatted table.

	Report() – Generate compliance alerts for fuel, speed, and maintenance.


	Problems and Complexities: The main problem was reliably detecting when the user entered the wrong type of data (like text instead of a number) using scanf. A related issue was that this incorrect input would remain in the program's input "waiting line," causing all subsequent attempts to read numbers to fail immediately, leading to repeated error messages if not handled properly by clearing this leftover input.


	Future Development: In future I would like to add live(real time) location using redar tracking system...and I will also add the world map with flight route and directions with real time weather forecast for ensuring more safety and maximum use of an aircraft which will increase the net profit.


This system provides a console-based interface that is user-friendly and effective for airline staff to maintain up-to-date fleet information and ensure operational safety and the maximum use of and aircraft while maintaining minimum profit.
