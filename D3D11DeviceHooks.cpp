#include "D3D11DeviceHooks.h"


D3D11DeviceHooks::D3D11DeviceHooks(ID3D11Device* inner, ovrHmd hmd){
	this->inner = inner;
	this->hmd = hmd;
}
