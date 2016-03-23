///*
// * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
// * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
// *
// * Code author(s):
// * 		Dan Orban (dtorban)
// */
//
//#ifndef VRGRAPHICSWINDOWFACTORY_H_
//#define VRGRAPHICSWINDOWFACTORY_H_
//
//#include "display/factories/VRTypedDisplayFactory.h"
//#include "main/VRSystem.h"
//#include "display/nodes/graphics/VRGraphicsWindowNode.h"
//
//namespace MinVR {
//
//class VRGraphicsWindowFactory : public VRTypedDisplayFactory {
//public:
//	virtual ~VRGraphicsWindowFactory();
//
//protected:
//	VRGraphicsWindowFactory(VRSystem* vrSystem);
//	VRDisplayNode* create(VRDataIndex& config, const std::string nameSpace, std::string type);
//	virtual VRGraphicsWindowNode* createWindow(VRDataIndex& config, const std::string nameSpace, std::string type) = 0;
//
//private:
//	VRSystem* m_vrSystem;
//};
//
//} /* namespace MinVR */
//
//#endif /* VRGRAPHICSWINDOWFACTORY_H_ */
