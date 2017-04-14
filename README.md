MaxEntropy
===
HOW TO COMPILE THIS PROJECT IN WINDOWS
---
* Step 0: Open cmd, and change directory to project directory. </br> Use this command `cd /your/project/path/MaxEntropy`. </br>
* Step 1: Create a new directory in MaxEntropy. Use this command `mkdir build` </br>
* Step 2: Change your directory. Use this command `cd build`. </br>
* Step 3: Build project. Use this command </br> `cmake .. -DEIGEN3_INCLUDE_DIR=/your/eigen/path -DN3L_INCLUDE_DIR=/your/LibN3L-2.0/path`. </br>
* Step 4: Then you can double click "MaxEntropy.sln" to open this project. </br>
* Step 5: Now you can compile this project by Visual Studio. </br>
* Step 6: If you want to run this project.Please open project properties and add this argument. </br>
`-train /your/training/corpus -dev /your/development/corpus -test /your/test/corpus -option /your/option/file -l` </br>

NOTE
---
Make sure you have eigen ,LibN3L-2.0, cmake and visual studio 2013 version (or newer). </br>
* Eigen:http://eigen.tuxfamily.org/index.php?title=Main_Page </br>
* LibN3L-2.0:https://github.com/zhangmeishan/LibN3L-2.0 </br>
* cmake:https://cmake.org/</br>
