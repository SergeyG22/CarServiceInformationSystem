# CarServiceInformationSystem

The applications allows you to keep records of car service

### Installing dependencies

Python interpreter and the Conan package manager must be installed.
CMake 3.14 or higher should also be installed.

To install Conan, enter the following command:

```
pip3 install conan 
```

To check that the Conan is installed correctly enter in cmd:

```
conan --version
```

Download the sources and install the required dependencies:
```
git clone https://github.com/SergeyG22/CarServiceInformationSystem.git
cd CarServiceInformationSystem
cd cmake
conan install ../scripts
```

To switch between Debug or Release builds:

```
cd cmake
conan install -s build_type=Debug ../scripts 
```
```
cd cmake
conan install -s build_type=Release ../scripts 
```

After these commands, Conan will build a dependency graph and download the necessary packages.

### Building from source
```
cd CarServiceInformationSystem
mkdir build
cd build
cmake ..
```

For Linux enter (debug or release version):

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```
```
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

For Windows enter (debug or release version):

```
cmake --build build --config Debug
```
```
cmake --build build --config Release
```
After that, an executable file will appear in 'build' the directory

**To work successfully, the "resource" folder must be located on the directory above that of the executable file**<br><br>
