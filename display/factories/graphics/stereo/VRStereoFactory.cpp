/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/factories/graphics/stereo/VRStereoFactory.h>
#include "display/nodes/graphics/stereo/VRSideBySideNode.h"

namespace MinVR {

VRStereoFactory::VRStereoFactory(VRSystem* vrSystem) : m_vrSystem(vrSystem) {
	// TODO Auto-generated constructor stub

}

VRStereoFactory::~VRStereoFactory() {
	// TODO Auto-generated destructor stub
}

VRDisplay* VRStereoFactory::create(VRDataIndex& config,
		const std::string nameSpace) {

	std::string ending = "SideBySideStereo";

	if(std::equal(ending.rbegin(), ending.rend(), nameSpace.rbegin()))
	{
		std::cout << "True " << nameSpace << std::endl;
		VRSideBySideNode* sideBySideNode = new VRSideBySideNode();
		createChildren<VRSideBySideNode, VRGraphicsContextChild>(sideBySideNode, m_vrSystem->getDisplayFactory(), config, nameSpace);
		return sideBySideNode;
	}

	return NULL;
}

} /* namespace MinVR */
