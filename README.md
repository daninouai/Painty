<img src="https://raw.githubusercontent.com/daninouai/Painty/master/icons/icon.png" alt="logo" align="left" height="100"/>

# Painty (GUI) <br> ![version badge](https://img.shields.io/badge/latest--release-v1.0-blue)

### Painting Program with OpenGL and Qt ###

A painting program created using OpenGL and Qt is an excellent example that showcases the synergy between these two libraries. This program utilizes various tools and features to provide a comprehensive drawing experience. Some of the key tools include:

* Pencil Tool: Allows users to draw freehand lines, similar to using a pencil.

* Spray Tool: Simulates a spray paint effect, creating a scattered pattern of color.

* Circle Drawing Tool: Enables users to draw circles of different sizes.

* Rectangle and Square Drawing Tools: Allows the creation of both rectangles and squares.

* Line Drawing Tool: Provides a tool for drawing straight lines.

* Text Drawing Tool: Allows users to add text and strings to the canvas, with options for changing text color and size.

* Eraser Tool: Functions as an eraser to remove drawn elements.

Additionally, the program supports features like changing the color and size of the text. The ability to save the created content in PNG format adds a practical dimension to the application.

Overall, this painting program demonstrates the capabilities of Qt for creating a user-friendly interface and handling input, while OpenGL enhances the graphical rendering, enabling smooth and efficient drawing operations.

| Path | Description |
|-----------------|-------------|
| `File => Save as Image`       | to save in png format |

## Build and Run Instructions

To build and run the Painty project using CMake and `make`, follow these steps:

Create a Build Directory:** First, create a directory for the build files and navigate into it:
   ```bash
  mkdir -p cmake-build-debug
  cd cmake-build-debug
  ```
Then cmake and make
  ```
  cmake ..
  make
  ```
Finally rut it!
```
./Painty
```
   
   

# Libraries
* [OpenGL](https://www.opengl.org/)
* [Qt](https://www.qt.io/)

# Authors
* [daninouai](https://github.com/daninouai)

# Preview
![Screenshot_20230418_0033438](https://raw.githubusercontent.com/daninouai/Painty/master/Painty.gif)
