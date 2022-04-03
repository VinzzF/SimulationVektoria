#pragma once
#include "VektoriaMath/HVector.h"

#include <glm/glm.hpp>

static Vektoria::CHVector convertVector(const glm::vec3& vec)
{
	return Vektoria::CHVector(vec.x, vec.y, vec.z);
}

static glm::vec3 convertVector(const Vektoria::CHVector& vec)
{
	return glm::vec3(vec.x, vec.y, vec.z);
}