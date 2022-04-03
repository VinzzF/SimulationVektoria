#pragma once

#include "SimulationScene.h"

/**
 * An empty black scene
 */
class EmptyScene : public SimulationScene
{
public:
	explicit EmptyScene();
	~EmptyScene();

	void update(float timeDelta) override;
	void reset() override;

protected:

};