#pragma once

class Controller{
	
public:
	virtual ~Controller() = default;
	virtual void eventLoop() = 0;
};