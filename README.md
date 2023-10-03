# OXDMarketplace
![](shots/marketplace.jpg)

## Market Management System
This project is a simple market management system written in C++. It allows users to manage the inventory of a shop, including adding new items, updating existing items, deleting items, and generating reports. The system uses a struct to represent a good, with fields for name, price, brand, and the number of items in stock.
This system has the ability to save data into a file and subsequently read from that file to load the information of the most recent save.
## demo:
wait for it to load
![](shots/Rec%200017.gif)

## Installation
To Install and run this project, you need to have a C++ compiler installed on your machine. Then, copy the code into a file with a .cpp extension, compile it using the compiler, and run the generated executable file.
```c++
cd src
g++ main.cpp
a.exe
```
the save file is stored near the .exe file and has the default name `save.hasan`
## Usage
When running the program, the user is presented with a menu where they can choose to add new goods, update old goods, generate reports, and exit the system. When entering new goods, the user is asked to input the name, price, brand, and the number of items in stock. When updating old goods, the user is asked to input the new name, price, and number of items in stock. The system will find the old good with the same name and brand and update its information. The system can also generate a report showing all the goods in the store, sorted by name, price, brand, and the number of items in stock.

## Contributing
If you want to contribute to this project, please fork the repository, make your changes, and then submit a pull request.

## License
This project is licensed under the MIT [License](LICENCE).

## shots:
![](shots/Shot%200004.png)