CGRA-FEUP
=========

A repository to host CGRA projects.

###How to open project on eclipse:
1. Open eclipse;
2. Open the C/C++ perspective;
3. Create new "Makefile Project with Existing Code";
4.
  - Name your project;
  - Select the project folder;
  - Select Linux GCC toolchain;
5. Press finish.

###How to install CGFLib on ubuntu:
1. Run the following command:  
````sudo apt-get install freeglut3-dev libglew-dev````

2. Install these package:
  - http://packages.ubuntu.com/nl/raring/libglui2c2
  - http://packages.ubuntu.com/nl/raring/libglui-dev
###Important notes:
! Do not erase newCGRAProject.sh neither CGRA Application folder !  
These are required to create new projects easily using a script.

If you want to use the script, you just need to download NewCGRAProject.zip and extract the contents.

###How to run the script:
1. Open the terminal
2. Navigate to the script folder
3. Run the command:
  - sh newCGRAProject.sh newProjectName
