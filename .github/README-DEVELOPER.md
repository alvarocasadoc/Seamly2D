# Build Seamly2D

## Basic Software Prerequisites:  
* [Qt 5.15.2](https://www.qt.io/download-open-source) (includes Qt, QtCreator, QtChooser, and Qt Maintenance Tool)
* [Git](https://git-scm.com/downloads) or [Github Desktop for Windows and MacOS](https://desktop.github.com)
* Compiler - MSVC 2022, gcc, and g++ are included with QtCreator, and you can add or update them using the Qt Maintenance Tool (Maintenance.exe).
* Pdftops (from XpdfReader or poppler) - Required to create PS or EPS layout files. 
* Check the sections below for your operating system to find additional installation requirements.

## Development methods and styles:
   * [GitHub Flow workflow](https://githubflow.github.io)
   * [Gibhub commit message style guide](https://www.conventionalcommits.org/en/v1.0.0/)
   * [Github issue description style guide](https://guides.github.com/features/issues/)

## Build method:
   * Read more about code styles and other developer items of interest on our [Developer wiki](https://github.com/FashionFreedom/Seamly2D/wiki).
   * Review our [GitHub Action CI script](workflows/build-release.yml).
___________________________________________________
## Build on Linux

  _These instructions apply in general, with Ubuntu 22.04 as example_

* Install Qt 5.15.2
  * Example for Ubuntu 22.04: Install the following packages to have Qt5 build environment ready: 
      ```
      $ sudo apt install -y libfuse2 qt5-qmake qtbase5-dev libqt5xmlpatterns5-dev libqt5svg5-dev qttools5-dev-tools
      ```
* Install QtCreator https://wiki.qt.io/VendorPackages
* Install Additional libraries
  - gnu compiler
  - poppler (pdftops)
  - Example for Ubuntu 22.04:
    ```
    $ sudo apt install -y build-essential git poppler-tools
    ```
* Build and install:  
  ```
  $ qmake Seamly2D.pro CONFIG+=noDebugSymbols
  $ make -j$(nproc)
  $ sudo make install
  ```
  _Note: The default prefix for command `make install` is `/usr`.  To define another prefix, build with qmake's PREFIX option. This example sets `/usr/local` as the new prefix for Seamly's installation binary files:_
    ```
    $ qmake PREFIX=/usr/local Seamly2D.pro CONFIG+=noDebugSymbols
    ```
* Copy pdftops to Seamly build directory if you need to create post script (.ps and .eps) pattern piece layouts.

## Build on MacOSX and Windows 10/11
1. MacOS only: 
    * Read about Qt for macOS [here](https://doc.qt.io/qt-5/macos.html)
    * Install [Xcode 11](https://developer.apple.com/download/all/)
    * Setup/validate build environment. Read more [here](https://doc.qt.io/qt-5/macos.html#build-environment).
      * Switch to Xcode: `sudo xcode-select --switch /Applications/Xcode.app`
      * Validate clang compiler points to Xcode: `xcrun -sdk macosx -find clang`
      * Validate SDK version (macOS 10.15): `xcrun -sdk macosx --show-sdk-path`
    * Install Xpdf: `sudo port install xpdf`

2. Both MacOS and Windows:
    * Download & run the [Qt unified installer](https://www.qt.io/download-qt-installer). Create a Qt account for open source Community Edition if you don't have one.  
      - Select:
        * Custom Installation
        * Qt  - _Minimize your options, otherwise your download size could be in Gs_
          * Qt 5.15.2
            * MSVC 2019
            * Qt Debug Information Files
          * Developer and Designer Tools
            * Qt Creator
            * Qt Creator CDB Debugger Support
            * Debugging Tools for Windows
            * Qt Creator Debug Symbols
            (Qt Maintenance Tool is always installed with Developer & Designer Tools - this will be highlighted)

3. Windows only: 
    * Download [XpdfReader](http://www.xpdfreader.com/download.html) for Windows. Extract to `C:/Program Files`. Rename folder to `C:/Program Files/Xpdf`.
    * Read about Qt for Windows [here](https://doc.qt.io/qt-5/windows.html).
    * Add Qt and QtCreator directories to the Windows PATH environment variable through Control Panel:  
      `[Control Panel | System And Security | System | Advanced Tab | Environment Variables button]`
3. Mac only for signing and notarizing:
    * Enable signing and notarizing at qmake step:
      ```
      qmake Seamly2D.pro CONFIG+=macSign
      ```
4. Both MacOS and Windows: 
    * Build the Seamly2D project
      * To build with Qt's *QtCreator* IDE:
        * Create your compiler kit.  Read more about adding compilers [on the Qt website](https://doc.qt.io/qtcreator/creator-tool-chains.html).  
        * Complete your build settings.  Read more about build settings [here](https://doc.qt.io/qtcreator/creator-build-settings.html).
        * Open the Seamly2D project with 'File > Open File or Project'. Navigate to the 'seamly2d/src' directory and select 'Seamly2D.pro'. 
        * Open the Configure Project tab and select your compiler kit. Read more [here](https://doc.qt.io/qtcreator/creator-project-opening.html).      
        * Build with the 'Build and Run Kit Selector' icon, or use 'Build' and 'Run' from the Tools menu. Read more [here](https://doc.qt.io/qtcreator/creator-building-targets.html). 
      * To build with Qt's *qmake* from a terminal window:  
        * Read more about jom [here](https://wiki.qt.io/Jom)
        * Read more about nmake [here](https://learn.microsoft.com/en-us/cpp/build/reference/nmake-reference?view=msvc-170)
          ```
          cd $SOURCE_DIRECTORY\build
          qmake ..\Seamly2D.pro CONFIG+=noDebugSymbols
          nmake      # (or jom. Assign multiple CPUs to speed up compilation time but don't use all - leave at least one CPU for your OS.) 
          ```
      * Copy the `C:\Program Files\Xpdf\bin64\pdftops.exe` (or bin32) file to the Seamly build directory to enable creation of post script (.ps and .eps) pattern piece layouts.