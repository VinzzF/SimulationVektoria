#pragma once
#include "SimulationScene.h"

class EmptyScene : public SimulationScene
{
public:
	explicit EmptyScene();
	~EmptyScene();

	void update(float timeDelta) override;
	void reset() override;

private:

};