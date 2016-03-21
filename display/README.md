# Display Node Architecture

## VRDisplayNode

VRDisplayNode is the fundamental class that can be inherited to create a different types of displays.  It assumes that the subclass has complete control of its children, but a user cannot add or delete the children directly.  This gives more control of types of children that can be added to a node.  For example, a graphics window node may require that its children are only of a type that have graphics contexts.

## Folder Structure

The display directory is separated into several folders to handle different levels complexity and functionality:

* **factories** - Contains factories that can create VRDisplayNodes.  This folder mostly allows users to extend MinVR through plugins.  Users can create their own factories which parse a VRDataIndex.  These then can be added to the VRMain list of available display factories.
* **interfaces** - Contains a more genearal framework, which allows more *advanced* users of MinVR to extend MinVR beyond the VRDisplayNode architecture.
* **nodes** - Contains the base display nodes that are defined in MinVR, specifically for graphics and command line rendering.
* **renderers** - Contains the base renderers defined in MinVR, specifically for handling render callbacks and controlling state.

***The base display directory contains the VRDisplayNode class which is all you need to start creating your own displays.***

## Quick Start Guide

#### Createing a New Display

To create a new display, simply inherit from MinVR::VRDisplayNode and override the render function:

  ```c++
  #include "display/VRDisplayNode.h"
  #include <iostream>
  
  /* MyDisplayNode sets myValue and uses the command line to display. */
  class MyDisplayNode : public MinVR::VRDisplayNode {
  
    void render(MinVR::VRRenderer renderer) {
      std::cout << "This is called when this display node renders." << std::endl;
    
      // Pushes the current render state for node state changes
      renderer->pushState();
      
      // Add a value to state to be used by the user defined render function
      renderer.getState().setValue("myValue", 7);
      
      // Calls the user defined render function
      renderer.render();
      
      // Pops the current render state to revert to the previous state
      renderer->popState();
    }
  }
  ```
  
To use the display, create a MinVR::VRRenderer and use the display to call the user defined function:
    
  ```c++
  #include "MyDisplayNode.h"
  #include "display/renderers/VRCallbackRenderer.h"
  
  /* User defined function which the display node calls */
  void userRender(VRRenderState& state) {
    int myValue = renderer.getState().getValue("myValue");
    std::cout << "My user defined render function.  myValue: " << myValue << std::endl;
  }
  
  int main(int argc, char **argv) {
    // Create display
    MyDisplayNode myDisplayNode;
    
    // Create VRCallbackRenderer which encapsulates a simple function pointer
    VRCallbackRenderer renderer(userRender);
    
    // Call render function
    myDisplayNode.render(renderer);
  }
  ```
  



