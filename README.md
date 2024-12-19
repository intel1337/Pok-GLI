# Poké-GLI 

#  Poké GLI is a multiplayer pokémon fighting game

GLI stands for Graphical line Interface
It means that the game will show ASCII images instead of real images
It's a lightweight game with tons of features, the main ones is Multiplayer, Terminal Interface and Finally Account and Elo System

Thanks to :
- pokemondb.net
- stackoverflow.com
- Unix Man
- Geeks4Geeks
- ManyTools.org
- asciiart.eu
- C man pages
- kiwiframework.dev

# Requirements

```
Run on an Unix System
(Optional) : Have GCC to build the app
UTF-8 Terminal
(Optional) : A server
```

# Start & Setup

Building : ⚠️ If you downloaded from the lastest release you don't have to build it manually

```
gcc client.c -o client
gcc login.c -o login
gcc register.c -o register
gcc play.c -o play
```

Running :

Run the Executable file that run everyservice for the server
```
./start
```
Run your client
```
./client
```
# Features :
### Server sided :

- Database Management
- Login and Register Services
- dynamic userid database
- random queue without any SBMM
- Username / userid ban
### Client sided :
- Ascii pokémons sprites
- Fair and fun fighthing system
- MMR system with an algorithm ensuring fair gains / losses
- 20 different pokémons with different abilities
- Register and Login system


# UML diagram and Cases
![diagram](https://github.com/user-attachments/assets/7138a0e6-96ac-4697-98bf-5a3480853c06)
