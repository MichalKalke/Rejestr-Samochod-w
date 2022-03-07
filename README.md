# Vehicle Base

This program is a cmd application for a vehilce base of users.

1. At the begginig, you can login as an admin or regular user or use the guest account.
Logging is vaildated by regex expression.

2. Then you can use the methods listed below depending on whether you are an admin or not.

## **Regular user methods:**
- Show all vehicles in the base without fragile data (id of the vehicle)
- Show all users in the base without fragile data (only firstname, surrname and city)
- Change user's password
- Find which vehicles are in the specific city
- Show user's car with all data
- Show who is the owner of given brand
- Show all vehicles of given person

## **Admin methods:**
- All regular user methods
- Change any user's password
- Show connections between users and their vehicles
- Add new person to the base 
- Delete given person from the base
- Add new vehicle to the person
- Delete given vehicle from a person
- Add new user
- Delete given user
- Add new vehicle to the base
- Delete given vehicle from the base

Adding new stuff is also validated by regex expressions. 

3. At the end you can choose whether you want to quit or use another method.

## Input files
There are 4 .txt files:
- users 
- connections (connects vehicles with persons)
- persons
- vehicles

