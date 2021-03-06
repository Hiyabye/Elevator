<!-- Title of Project -->
Elevator
========

<!-- Some badges giving the reader a summary of the project -->
[![CodeFactor](https://www.codefactor.io/repository/github/hiyabye/elevator/badge)](https://www.codefactor.io/repository/github/hiyabye/elevator)
[![GitHub license](https://img.shields.io/github/license/Hiyabye/Elevator)](https://github.com/Hiyabye/Elevator/blob/master/LICENSE)
![C/C++ CI](https://github.com/Hiyabye/Elevator/workflows/C/C++%20CI/badge.svg?branch=master)

<!-- Simple description of the project -->
This is a simple elevator algorithm written in C.

<!-- This part gives the reader a faster way to find information -->
## Table of Contents
* [About](#about)
  * [How it works](#how-it-works)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Installing](#installing)
  * [Contributing](#contributing)
* [License](#license)
* [Future Goals](#future-goals)
* [Acknowledgments](#acknowledgments)
  * [Why I made this](#why-i-made-this)
  * [Contact](#contact)

<!-- This section explains characteristics of the project -->
## About
<!-- Information about the project -->
### How it works
1. First, it asks the person if they want to take the elevator.
2. If the person accepts, it asks again which direction to go.
3. Then, it finds the closest elevator to the person and moves it towards them.
4. When the person gets in, the program asks the person which floor to go.
5. After getting input again, it goes to that floor and drops the person there.
6. The instructions above is repeated over and over again.
7. If every people doesn't call the elevator, the program will end.

<!-- Framework of the project -->
### Built With
* [Visual Studio Code](https://code.visualstudio.com/)

<!-- This section explains how to install the project -->
## Getting Started
### Installing
<!-- Short sentence about the what OS can this be installed -->
1. Clone the repository using git.
```sh
git clone https://github.com/Hiyabye/Elevator.git
```
2. Build Makefile with CMake
```sh
cd Elevator
mkdir build
cd build
cmake ..
```
3. Build the program with Makefile
```sh
make all
```

<!-- This section is about the license of the project -->
## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

<!-- This section explains the ultimate goal for the project -->
## Future Goals
* Refactor the code.
* Change function names to increase readability.
* Improve algorithm of how the elevator works.
* Replace everything with pointers.
* Add pictures to README. (Examples of how it works)
* Good-looking interface.

<!-- This section explains stuff the reader should better know -->
## Acknowledgments
<!-- The motivation of making this -->
### Why I made this
I'm learning programming mainly in C, and my teacher gave me this problem to do for a challenge.

<!-- If you don't need this remove it -->
### Contact
If you have any questions regarding the project, feel free to email me.

* Hiyabye - hiyabye0465@gmail.com
