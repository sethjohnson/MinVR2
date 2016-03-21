# Display Node Architecture

VRDisplayNode is the fundamental class that can be inherited to create a different types of displays. It assumes that the 
node is read only so that subclasses have more control over which types can be  added to the display node.  For example, 
a graphics window node can only have sub-nodes which assume a context.  If you want to create a node that is also 
writable, inherit from VRBasicDisplayNode instead.

## Quick Start Guide

#### Createing a new display

Here is simple example application of creating a new command line display node that overrides the render function:

  ```
  #include "display/VRDisplayNode.h"
  #include "display/renderers/VRCallbackRenderer.h"
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
  
  /* User defined function which the display node calls */
  void userRender(VRRenderState& state) {
    int myValue = renderer.getState().getValue("myValue");
    std::cout << "My user defined render function.  myValue: " << myValue << std::endl;
  }
  
  int main(int argc, char **argv) {
    // Create display
    MyDisplayNode myDisplayNode;
    
    // Create user renderer
    VRCallbackRenderer renderer(userRender);
    
    // Call render function
    myDisplayNode.render(renderer);
  }
  ```

