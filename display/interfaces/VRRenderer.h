/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRRENDERER_H_
#define VRRENDERER_H_

#include "VRRenderState.h"

namespace MinVR {

/*
 * VRRenderer is an interface that allows the user to define how state is controlled and
 * specify render functions.
 */
class VRRenderer {
public:
	virtual ~VRRenderer() {}

	// ------------ User defined render functions: -------------
	// updateFrame() allows a user to specify a function which handles per frame functionality.
	// for example, a user may want to use this function to update VBO objects per frame if needed.
	virtual void updateFrame() = 0;
	// render() allows a user to specify a render function which displays application specific graphics.
	virtual void render() = 0;

	// ------------ State control functions: -------------
	// Returns the current state
	virtual VRRenderState& getState() = 0;
	// Pushes a state, which usually implies that previous state information is available and changes to the state
	// will not affect the previous states
	virtual void pushState() = 0;
	// Pops the state, so the state will return to a previous state and undo changes from the popped state.
	virtual void popState() = 0;
	// Resets the state
	virtual void resetState() = 0;

};

} /* namespace MinVR */

#endif /* VRRENDERER_H_ */
