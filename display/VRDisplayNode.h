/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRDISPLAYNODE_H_
#define VRDISPLAYNODE_H_

#include "display/renderers/VRRenderHandler.h"
#include <vector>

namespace MinVR {

/*
 * VRDisplayNode is the fundamental class that can be inherited to create a different types of displays.
 * It assumes that the node is read only so that subclasses have more control over which types can be
 * added to the display node.  For example, a graphics window node can only have sub-nodes which assume
 * a context.  If you want to create a node that is also writable, inherit from VRBasicDisplayNode instead.
 */
class VRDisplayNode {
public:
	VRDisplayNode();

	// VRDisplayNode assumes that it owns its children, so it will delete its children when destroyed.  If
	// this functionality is not desired, create an adapter display node with a weak pointer.
	virtual ~VRDisplayNode();

	// Calls render function on each of the display node's children.  If there are no children, then we are
	// at a leaf node and renderer.render() is called.  VRRenderer allows the display to control state and
	// call user defined render functions.
	virtual void render(VRRenderHandler& renderer);

	// Waits for rendering to complete on the display node
	virtual void waitForRenderToComplete();

	// Actually displays the rendered results
	virtual void displayTheFinishedRendering();

	// Returns the display node's children
	virtual const std::vector<VRDisplayNode*>& getChildren() const;

	// Adds a display node child
	void addChild(VRDisplayNode* child);

	// Clears the children in a node
	void clearChildren(bool destroyChildren = false);

//protected:
//	// VRDisplayNode construtor is private because it must be inherited and cannot be instantiated on its own
//
//	// Internal methods for manipulating display node children in the subclass
//	void addChildInternal(VRDisplayNode* child);
//	void insertChildInternal(VRDisplayNode* child, int index);
//	void clearChildrenInternal(bool destroyChildren = false);

private:
	std::vector<VRDisplayNode*> m_children;
};

///*
// * VREditableDisplayNode<ChildType> allows a user to specify a specific allowable node types that
// * can be added to the display node.  In general gives more fine grained control of which Displays
// * can be added and rendered under the node.  VRBasicDisplayNode essentially sets the ChildType
// * of VREditableDisplayNode to VRDisplayNode.
// */
//template<typename ChildType>
//class VREditableDisplayNode : public VRDisplayNode {
//public:
//	VREditableDisplayNode() {}
//	virtual ~VREditableDisplayNode() {}
//
//	// Specific child type implementation of display nodes
//	virtual void addChild(ChildType* child);
//	virtual void insertChild(ChildType* child, int index);
//	virtual void clearChildren(bool destroyChildren = false);
//};
//
///*
// * VRBasicDisplayNode is the node that should be inherited to create simple display nodes which
// * also have other display nodes as children with no restriction as to the type of nodes that can
// * be added.
// */
//typedef VREditableDisplayNode<VRDisplayNode> VRBasicDisplayNode;
//
//// --------------- VREditableDisplayNode<ChildType> Template implementation ------------------------
//
//template<typename ChildType>
//void VREditableDisplayNode<ChildType>::addChild(ChildType* child) {
//	VRDisplayNode* node = dynamic_cast<VRDisplayNode*>(child);
//	if (node) {
//		addChildInternal(node);
//	}
//}
//
//template<typename ChildType>
//void VREditableDisplayNode<ChildType>::insertChild(ChildType* child, int index) {
//	VRDisplayNode* node = dynamic_cast<VRDisplayNode*>(child);
//	if (node) {
//		insertChildInternal(node, index);
//	}
//}
//
//template<typename ChildType>
//void VREditableDisplayNode<ChildType>::clearChildren(bool destroyChildren) {
//	clearChildrenInternal(destroyChildren);
//}

} /* namespace MinVR */

#endif /* VRDISPLAYNODE_H_ */
