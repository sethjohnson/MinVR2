/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRDISPLAYFACTORY_H_
#define VRDISPLAYFACTORY_H_

#include "display/interfaces/VRDisplay.h"
#include "config/VRDataIndex.h"

namespace MinVR {

class VRDisplayFactory {
public:
	virtual ~VRDisplayFactory() {}

	virtual VRDisplay* create(VRDataIndex& config, const std::string nameSpace) = 0;

	template<typename DisplayNodeType, typename ChildNodeType>
	static void createChildren(DisplayNodeType* display, VRDisplayFactory& factory, VRDataIndex& config, const std::string nameSpace);
};

template<typename DisplayNodeType, typename ChildNodeType>
void VRDisplayFactory::createChildren(DisplayNodeType* display, VRDisplayFactory& factory, VRDataIndex& config, const std::string nameSpace)
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

} /* namespace MinVR */

#endif /* VRDISPLAYFACTORY_H_ */
