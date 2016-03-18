/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRHASDISPLAYCHILDREN_H_
#define VRHASDISPLAYCHILDREN_H_

#include "VRDisplayNode.h"

namespace MinVR {

class VRHasDisplayChildrenBase {
public:
	virtual ~VRHasDisplayChildrenBase() {}

protected:
	VRHasDisplayChildrenBase(VRDisplayNode* node) : m_node(node) {}

	void addNodeChild(VRDisplayNode* child) {
		m_node->addChildInternal(child);
	}

	void insertNodeChild(VRDisplayNode* child, int index) {
		m_node->insertChildInternal(child, index);
	}

	void clearNodeChildren(bool destroyChildren) {
		m_node->clearChildrenInternal(destroyChildren);
	}

private:
	VRDisplayNode* m_node;
};

template<typename T>
class VRHasDisplayChildren : VRHasDisplayChildrenBase {
public:
	virtual ~VRHasDisplayChildren() {}

	virtual void addChild(T* child) {
		VRHasDisplayChildrenBase::addNodeChild(child);
	}

	virtual void insertChild(T* child, int index) {
		VRHasDisplayChildrenBase::insertNodeChild(child, index);
	}

	virtual void clearChildren(bool destroyChildren = false) {
		VRHasDisplayChildrenBase::clearNodeChildren(destroyChildren);
	}

protected:
	VRHasDisplayChildren(VRDisplayNode* node) : VRHasDisplayChildrenBase(node) {}

};

} /* namespace MinVR */

#endif /* VRHASCHILDREN_H_ */
