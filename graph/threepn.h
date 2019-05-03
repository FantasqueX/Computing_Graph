#pragma once
#include "node.h"

class Cond:public ThreeParentsNode
{
	public:
		using ThreeParentsNode::ThreeParentsNode;
		float func() override;
};