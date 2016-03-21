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
public:
	virtual ~VRDisplayNode();

	virtual void render(VRRenderer& renderer);

	virtual const std::vector<VRDisplayNode*>& getChildren() const;

protected:
	VRDisplayNode();
	void addChildInternal(VRDisplayNode* child);
	void insertChildInternal(VRDisplayNode* child, int index);
	void clearChildrenInternal(bool destroyChildren = false);

private:
	std::vector<VRDisplayNode*> m_children;
};

template<typename ChildType>
class VREditableDisplayNode : public VRDisplayNode {
public:
	VREditableDisplayNode() {}
	virtual ~VREditableDisplayNode() {}

	virtual void addChild(ChildType* child);
	virtual void insertChild(ChildType* child, int index);
	virtual void clearChildren(bool destroyChildren = false);
};

typedef VREditableDisplayNode<VRDisplayNode> VRBasicDisplayNode;

template<typename ChildType>
void VREditableDisplayNode<ChildType>::addChild(ChildType* child) {
	VRDisplayNode* node = dynamic_cast<VRDisplayNode*>(child);
	if (node) {
		addChildInternal(node);
	}
}

template<typename ChildType>
void VREditableDisplayNode<ChildType>::insertChild(ChildType* child, int index) {
	VRDisplayNode* node = dynamic_cast<VRDisplayNode*>(child);
	if (node) {
		insertChildInternal(node, index);
	}
}

template<typename ChildType>
void VREditableDisplayNode<ChildType>::clearChildren(bool destroyChildren) {
	clearChildrenInternal(destroyChildren);
}

} /* namespace MinVR */

#endif /* VRDISPLAYNODE_H_ */
