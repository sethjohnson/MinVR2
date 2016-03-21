/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRBASICRENDERER_H_
#define VRBASICRENDERER_H_

#include "display/interfaces/VRRenderer.h"

namespace MinVR {

/*
 * VRBasicRenderer has a simple implementation of controlling state.  When a state is pushed,
 * a new namespace in the VRDataIndex is created as a sub namespace to the current namespace.
 * This enables the use of the VRDataIndex for walking up a namespace tree.  The user defined
 * functions updateFrame(VRRenderState& state) and render(VRRenderState& state) still need to be
 * defined by the user.
 */
class VRBasicRenderer : public VRRenderer {
public:
	VRBasicRenderer();
	virtual ~VRBasicRenderer();

	// The render functions use a template method pattern to call updateFrame(state)
	void updateFrame();
	void render();

	// Render functions that need to be defined by the user
	virtual void updateFrame(VRRenderState& state) = 0;
	virtual void render(VRRenderState& state) = 0;

	// State controlling functions which are implemented using VRDataIndex namespaces
	VRRenderState& getState();
	void pushState();
	void popState();
	void resetState();

private:
	VRRenderState m_state;
	int m_nodeNum;
	std::vector<std::string> m_nameSpaces;
};

} /* namespace MinVR */

#endif /* VRBASICRENDERER_H_ */
