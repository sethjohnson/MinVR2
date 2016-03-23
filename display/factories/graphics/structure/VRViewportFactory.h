/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRVIEWPORTFACTORY_H_
#define VRVIEWPORTFACTORY_H_

#include "display/factories/VRDisplayFactory.h"
#include "main/VRSystem.h"

namespace MinVR {

class VRViewportFactory : public VRDisplayFactory {
public:
	VRViewportFactory(VRSystem* vrSystem, VRDisplayFactory* innerFactory);
	virtual ~VRViewportFactory();

	VRDisplayNode* create(VRDataIndex& config, const std::string nameSpace);

private:
	VRSystem* m_vrSystem;
	VRDisplayFactory* m_innerFactory;
};

} /* namespace MinVR */

#endif /* VRVIEWPORTFACTORY_H_ */
