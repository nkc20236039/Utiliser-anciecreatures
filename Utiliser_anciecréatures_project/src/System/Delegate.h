#pragma once

#include <vector>

template < class >
class Delegate {};

template < class Ret, class... Args >
class Delegate < Ret(Args...) > {
public:

private:
	
};