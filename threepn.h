#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "node.h"
class Cond:public ThreeParentsNode
{
	public:
		using ThreeParentsNode::ThreeParentsNode;
		float func(float x,float y,float z);
};