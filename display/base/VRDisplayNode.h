/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRDISPLAYNODE_H_
#define VRDISPLAYNODE_H_

#include "display/VRDisplay.h"
#include "display/VRDisplayFactory.h"
#include <vector>

namespace MinVR {

class VRDisplayNode : public VRDisplay {
friend class VRHasDisplayChildrenBase;
public:

	VRDisplayNode();
	virtual ~VRDisplayNode();

	virtual void render(VRRenderer& renderer);

	virtual const std::vector<VRDisplay*>& getChildren() const;

	template<typename DisplayNodeType, typename ChildNodeType>
	static void createChildren(DisplayNodeType* display, VRDisplayFactory& factory, VRDataIndex& config, const std::string nameSpace)
	{
		if (display)
		{
			VRContainer item = config.getValue(nameSpace);

			std::cout << nameSpace << std::endl;
			for (VRContainer::iterator f = item.begin(); f != item.end(); f++)
			{
				if (config.getType(*f) == VRCORETYPE_CONTAINER)
				{
					std::cout << *f << std::endl;
					VRDisplay* subDisplay = factory.create(config, *f);
					ChildNodeType* child = dynamic_cast<ChildNodeType*>(subDisplay);
					if (child)
					{
						display->addChild(child);
					}
					else if (subDisplay)
					{
						delete subDisplay;
					}
				}
			}
		}
	}

protected:
	void addChildInternal(VRDisplay* child);
	void insertChildInternal(VRDisplay* child, int index);
	void renderAtLeaf(VRRenderer& renderer);

private:
	std::vector<VRDisplay*> m_children;
};

} /* namespace MinVR */

#endif /* VRDISPLAYNODE_H_ */
