/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRSTEREOFACTORY_H_
#define VRSTEREOFACTORY_H_

#include "display/VRDisplayFactory.h"
#include "main/VRSystem.h"

namespace MinVR {

class VRStereoFactory : public VRDisplayFactory {
public:
	VRStereoFactory(VRSystem* vrSystem);
	virtual ~VRStereoFactory();

	VRDisplay* create(VRDataIndex& config, const std::string nameSpace);

private:
	VRSystem* m_vrSystem;
};

} /* namespace MinVR */

#endif /* VRSTEREOFACTORY_H_ */
