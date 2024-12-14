# GMockCatch2Danger
## Overview
GMockCatch2Danger is a C++ project that demonstrates the potential pitfalls of combining Google Mock (GMock) with the Catch2 testing framework. This repository accompanies the blog posts [The Danger of Combining GMock with Catch2](https://asiltureli.github.io/2024/11/22/gmockcatch2danger) and [The correct way to use GMock with Catch2](https://asiltureli.github.io/2024/11/26/gmockcatch2adapter) 

1. TestGMockCatch2WithMain provides the sample code to illustrate why integrating these two frameworks out-of-the-box can lead to unexpected behaviors in your unit tests.
2. TestGMockCatch2 provides the sample code to address a solution. 

## Prerequisites
Before you begin, ensure you have met the following requirements:

- Operating System: Windows, macOS, or Linux
- C++ Compiler: Supports C++20 (e.g., GCC 10+, Clang 10+, MSVC 2019+)
- CMake: Version 3.20 or higher
- Git: For cloning the repository

## Installation

1. Clone the Repository

```bash
git clone https://github.com/YourUsername/GMockCatch2Danger.git
cd GMockCatch2Danger
```
2. Create a Build Directory  
It's recommended to use an out-of-source build.

```bash
mkdir build
cd build
```

## Building the Project  
1. Configure the Project with CMake

```bash
cmake ..
```  
This command will automatically fetch the required dependencies (Catch2 and Google Mock) using CMake's ```FetchContent```.

2. Build the Executable

```bash
cmake --build .
```  
This will compile the TestGMockCatch2WithMain executable.

## Running the Tests
After building the project, you can run the tests using CTest or directly execute the test binary.

1. Using CTest

```bash
ctest
```

This will execute the tests and display the results. However, due to the integration issue between GMock and Catch2, failing tests might not be reported correctly.

2. Running the Test Executable Directly

```bash
./TestGMockCatch2WithMain
```

and

```bash
./TestGMockCatch2
```

Running the executable directly allows you to see the detailed output from Catch2 and potentially spot discrepancies in test results.
