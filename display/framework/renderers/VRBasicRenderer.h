/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRBASICRENDERER_H_
#define VRBASICRENDERER_H_

#include "display/framework/VRRenderer.h"

namespace MinVR {

class VRBasicRenderer : public VRRenderer {
public:
	VRBasicRenderer();
	virtual ~VRBasicRenderer();

	void updateFrame();
	void render();

	virtual void updateFrame(VRRenderState& state) = 0;
	virtual void render(VRRenderState& state) = 0;

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
