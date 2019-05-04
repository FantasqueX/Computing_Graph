#pragma once
#include "node.h"
extern bool asserted;

class Sum:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func();
};
class Subtraction:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func();
};
class Multiply:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func();
};
class Division:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func() override;
};
class EQU:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func() override;
};
class GTR:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func() override;
};
class GEQ:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func() override;
};
class LSS:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;
		float func() override;
};
class LEQ:public BinaryOperation
{
	public:
		using BinaryOperation::BinaryOperation;	
		float func() override;
};
