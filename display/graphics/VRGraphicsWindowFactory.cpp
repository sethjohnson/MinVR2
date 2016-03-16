/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/VRGraphicsWindowFactory.h>

namespace MinVR {

VRGraphicsWindowFactory::VRGraphicsWindowFactory(VRSystem* vrSystem) : m_vrSystem(vrSystem) {
	// TODO Auto-generated constructor stub

}

VRGraphicsWindowFactory::~VRGraphicsWindowFactory() {
	// TODO Auto-generated destructor stub
}

VRDisplay* VRGraphicsWindowFactory::create(VRDataIndex& config,
		const std::string nameSpace, std::string type) {
	if (config.exists("windowType", nameSpace))
	{
		VRGraphicsWindowNode* display = createWindow(config, nameSpace, config.getValue("windowType", nameSpace));
		if (display)
		{
			VRContainer item = config.getValue(nameSpace);

			std::cout << nameSpace << std::endl;
			for (VRContainer::iterator f = item.begin(); f != item.end(); f++)
			{
				if (config.getType(*f) == VRCORETYPE_CONTAINER)
				{
					std::cout << *f << std::endl;
					VRDisplay* subDisplay = m_vrSystem->getDisplayFactory().create(config, *f);
					VRGraphicsWindowChild* child = dynamic_cast<VRGraphicsWindowChild*>(subDisplay);
					if (child)
					{
						display->addChild(child);
					}
				}
			}
		}

		return display;
	}

	return NULL;
}

} /* namespace MinVR */
