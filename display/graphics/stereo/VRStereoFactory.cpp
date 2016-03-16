/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include <display/graphics/stereo/VRStereoFactory.h>
#include "VRSideBySideNode.h"

namespace MinVR {

VRStereoFactory::VRStereoFactory() {
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
		return new VRSideBySideNode();
	}

	return NULL;
}

} /* namespace MinVR */
