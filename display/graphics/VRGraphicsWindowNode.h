/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRGRAPHICSWINDOWNODE_H_
#define VRGRAPHICSWINDOWNODE_H_

#include "display/VRDisplayNode.h"
#include "VRGraphicsWindowChild.h"
#include "display/interfaces/synchronization/VRSynchronizedDisplay.h"
#include "display/graphics/structure/VRRect.h"
#include "display/graphics/structure/VRRectCalculator.h"
#include "display/graphics/structure/VRTile.h"

namespace MinVR {

class VRGraphicsWindowNode : public VRDisplayNode, public VRSynchronizedDisplay, public VRHasDisplayChildren<VRGraphicsWindowChild> {
public:
	virtual ~VRGraphicsWindowNode();

	virtual void render(VRRenderer& renderer);
	virtual void startRender(VRRenderer& renderer);
	virtual void waitForRenderComplete();
	virtual void synchronize();

	const VRRect& getRect() const {
		return m_rect;
	}

	void setRect(const VRRect& rect) {
		m_rect = rect;
	}

protected:
	VRGraphicsWindowNode(const VRRect& rect);
	virtual void updateState(VRRenderState& state);

	virtual std::string getContextType() = 0;
	virtual void setCurrentContext() = 0;
	virtual void clearCurrentContext() = 0;
	virtual void swapBuffers() = 0;
	virtual void flush() = 0;
	virtual void finish() = 0;

private:
	VRRectCalculator m_rectCalculator;
	VRRect m_rect;
};

} /* namespace MinVR */

#endif /* VRGRAPHICSWINDOWNODE_H_ */
