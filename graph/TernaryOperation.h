#pragma once
#include "node.h"

class Cond:public TernaryOperation
{
	public:
		using TernaryOperation::TernaryOperation;
		float func() override;
};