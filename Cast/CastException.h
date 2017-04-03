#pragma once
#pragma once

#include <exception>

class CastException
	: std::exception
{};

class ErrorChar
	: std::exception
{};

class ErrorOver
	: std::exception
{};