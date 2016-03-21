/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRDISPLAYNODE_H_
#define VRDISPLAYNODE_H_

#include "display/interfaces/VRDisplay.h"
#include <vector>

namespace MinVR {

class VRDisplayNode : public VRDisplay {
friend class VRHasDisplayChildrenBase;
public:
	VRDisplayNode();
	virtual ~VRDisplayNode();

	virtual void render(VRRenderer& renderer);

	virtual const std::vector<VRDisplay*>& getChildren() const;

protected:
	void addChildInternal(VRDisplay* child);
	void insertChildInternal(VRDisplay* child, int index);
	void clearChildrenInternal(bool destroyChildren = false);

private:
	std::vector<VRDisplay*> m_children;
};

} /* namespace MinVR */

#endif /* VRDISPLAYNODE_H_ */
