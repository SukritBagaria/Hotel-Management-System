# Hotel-Management-System
Hotel room and guest management system with 2 different versions: one based on CSV file handling in C++ and one based on MySQL for C++.

- Easy to use system that can be used by anyone with minimal training.
- Functionalitites include:
  1. Adding or modifying rooms.
  2. Searching for unoccupied rooms.
  3. Checking in new customers.
  4. Checking out customers.
  5. Saves customer data in a CSV file.
  6. Searching for customer data.
- The first iteration of the project stored data of customers and rooms using vector data structure. 
  But this model had a major issue that whenever we compile the program all the old data is lost. 
- To improve on the model, for the next iteration CSV file handling concepts are used to store data so that we are able to store data permenantly.
- Using CSV files to store data also made the data more readble.
- To improve the program further for large use cases like hotel chains, the data management system was changed to a MySQL server. 

Entity Relationship model(ER model) for database used in MYSQL :-

![alt text](https://github.com/SukritBagaria/Hotel-Management_System/blob/master/ER_Model.png?raw=true)


