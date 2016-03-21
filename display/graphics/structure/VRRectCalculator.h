/*
 * Copyright Regents of the University of Minnesota, 2016.  This software is released under the following license: http://opensource.org/licenses/
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#ifndef VRRECTCALCULATOR_H_
#define VRRECTCALCULATOR_H_

#include "display/framework/VRRenderer.h"
#include "VRRect.h"

namespace MinVR {

class VRRectCalculator {
public:
	VRRectCalculator(std::string inName, bool modifyTile = false);
	VRRectCalculator(std::string inName, std::string outName, bool modifyTile = false);
	virtual ~VRRectCalculator();

	VRRect calculate(VRRenderState& state, const VRRect& rect);

private:
	std::string m_inName;
	std::string m_outName;
	bool m_modifyTile;
};

} /* namespace MinVR */

#endif /* VRVIEWPORTCALCULATOR_H_ */
