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

class  ErrorType
	:std::exception
{};